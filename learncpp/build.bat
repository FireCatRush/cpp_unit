@echo off
rem ============================================================
rem  Build every exercise under learncpp\ (only changed files).
rem  Output goes to build\ next to this script.
rem
rem    build.bat            build all
rem    build.bat clean      delete build\
rem
rem  Compiler flags (-std, warnings) live at the top of Makefile.
rem  Usage notes (in Chinese) are in ..\README.md.
rem ============================================================
setlocal EnableExtensions
cd /d "%~dp0"

where g++ >nul 2>nul
if errorlevel 1 goto :no_compiler
where mingw32-make >nul 2>nul
if errorlevel 1 goto :no_make

if not defined NUMBER_OF_PROCESSORS set "NUMBER_OF_PROCESSORS=4"

echo Building...
mingw32-make -j%NUMBER_OF_PROCESSORS% %*
if errorlevel 1 goto :failed

echo.
echo Done. Executables are under build\
exit /b 0

:no_compiler
echo [ERROR] g++ not found in PATH. Check your MinGW installation.
goto :failed
:no_make
echo [ERROR] mingw32-make not found in PATH. Check your MinGW installation.
:failed
echo.
echo Build failed, see the messages above.
pause
exit /b 1
