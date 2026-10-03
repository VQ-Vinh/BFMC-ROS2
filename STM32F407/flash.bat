@echo off
rem Flash firmware qua ST-LINK. Usage: flash.bat [Debug|Release]
setlocal
set "PRESET=%~1"
if "%PRESET%"=="" set "PRESET=Debug"

cd /d "%~dp0"
set "ELF=build/%PRESET%/STM32F407.elf"
if not exist "%ELF%" (
    echo Khong tim thay %ELF%. Chay build.bat %PRESET% truoc.
    exit /b 1
)

openocd -f board/stm32f4discovery.cfg -c "program %ELF% verify reset exit" || exit /b 1
