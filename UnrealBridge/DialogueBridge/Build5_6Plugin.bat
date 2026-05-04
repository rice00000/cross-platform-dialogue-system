@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "UE_ROOT=D:\Program Files\Epic Games\UE_5.6"
set "PLUGIN_DIR=%~dp0"
set "PROJECT_DIR=%~dp0..\..\"

set "UPROJECT="
for %%F in ("%PROJECT_DIR%*.uproject") do (
    set "UPROJECT=%%~fF"
    set "PROJECT_NAME=%%~nF"
    goto FoundProject
)

echo No .uproject found at:
echo %PROJECT_DIR%
pause
exit /b 1

:FoundProject
set "TARGET=%PROJECT_NAME%Editor"

echo Project: %UPROJECT%
echo Target:  %TARGET%
echo Plugin:  %PLUGIN_DIR%

"%UE_ROOT%\Engine\Build\BatchFiles\Build.bat" %TARGET% Win64 Development "%UPROJECT%" -WaitMutex

pause