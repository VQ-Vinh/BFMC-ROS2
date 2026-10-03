@echo off
rem Build firmware. Usage: build.bat [Debug|Release]
setlocal
set "PRESET=%~1"
if "%PRESET%"=="" set "PRESET=Debug"

where arm-none-eabi-gcc >nul 2>nul
if errorlevel 1 set "PATH=C:\Program Files (x86)\Arm GNU Toolchain arm-none-eabi\14.2 rel1\bin;%PATH%"

cd /d "%~dp0"
cmake --preset %PRESET% || exit /b 1
cmake --build --preset %PRESET% || exit /b 1
