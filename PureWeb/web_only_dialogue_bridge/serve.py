import http.server, webbrowser, threading, os, subprocess, sys

PORT = 8000
DIR  = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

class Handler(http.server.SimpleHTTPRequestHandler):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, directory=DIR, **kwargs)
    def end_headers(self):
        self.send_header("Cache-Control", "no-store, max-age=0")
        super().end_headers()
    def log_message(self, fmt, *args):
        print(f"  {args[1]}  {self.path}")

def kill_old_servers():
    if os.name != "nt":
        return

    current_pid = os.getpid()
    result = subprocess.run(["netstat", "-ano"], capture_output=True, text=True)
    if result.returncode:
        return

    pids = set()
    for line in result.stdout.splitlines():
        parts = line.split()
        if len(parts) >= 5 and parts[1].endswith(f":{PORT}") and parts[3] == "LISTENING":
            try:
                pid = int(parts[-1])
            except ValueError:
                continue
            if pid != current_pid:
                pids.add(pid)

    for pid in sorted(pids):
        proc = subprocess.run(
            ["powershell", "-NoProfile", "-Command", f"(Get-Process -Id {pid}).ProcessName"],
            capture_output=True,
            text=True,
        )
        if proc.stdout.strip().lower() not in {"python", "pythonw", "py"}:
            print(f"Port {PORT} is used by PID {pid}; not killing non-Python process.", flush=True)
            continue
        subprocess.run(["taskkill", "/PID", str(pid), "/F"], capture_output=True, text=True)
        print(f"Killed old preview server PID {pid}.", flush=True)

if __name__ == "__main__":
    validator = os.path.join(DIR, "validate_dialogue_csv.py")
    if os.path.exists(validator) and subprocess.run([sys.executable, validator], cwd=DIR).returncode:
        sys.exit(1)

    kill_old_servers()

    url = f"http://localhost:{PORT}/hud.html?preview=1"
    print(f"Serving: {url}\nCtrl-C to stop\n", flush=True)
    threading.Timer(0.4, webbrowser.open, args=[url]).start()
    try:
        srv = http.server.ThreadingHTTPServer(("", PORT), Handler)
    except OSError as e:
        print(f"Could not start server on port {PORT}: {e}", flush=True)
        sys.exit(1)
    with srv:
        try:
            srv.serve_forever()
        except KeyboardInterrupt:
            print("\nStopped.")
