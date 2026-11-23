@echo off
rem ============================================================
rem  Compile and run one exercise.
rem
rem    cp_and_run.bat                        compile + run the most
rem                                          recently modified .cpp
rem    cp_and_run.bat chapter8\8.6\main.cpp  compile + run this file
rem    cp_and_run.bat x.cpp 1 2 3            extra args go to the program
rem
rem  You can also drag a .cpp file onto this script.
rem  If a folder contains main.cpp, the whole folder is linked into one
rem  program (multi-file exercises). Usage notes (Chinese): ..\README.md
rem ============================================================
setlocal EnableExtensions EnableDelayedExpansion
cd /d "%~dp0"
set "ROOT=%~dp0"
rem NOTE: shift() also moves %0, so remember the script folder first.

where g++ >nul 2>nul
if errorlevel 1 goto :no_compiler
where mingw32-make >nul 2>nul
if errorlevel 1 goto :no_make

set "RC=0"
set "SRC="

if "%~1"=="" goto :pick_newest
set "SRC=%~1"
shift
goto :collect

:pick_newest
for /f "usebackq delims=" %%f in (`powershell -NoProfile -Command "Get-ChildItem -Recurse -File -Filter *.cpp | Sort-Object LastWriteTime -Descending | Select-Object -First 1 -ExpandProperty FullName"`) do set "SRC=%%f"
if not defined SRC goto :no_source

rem ---- remaining args are passed to the program ----
:collect
set "ARGS="
:collect_loop
if "%~1"=="" goto :collected
set "ARGS=!ARGS! %~1"
shift
goto :collect_loop

:collected
rem make the path relative to this folder, keep both / and \ forms
set "SRC=!SRC:%ROOT%=!"
set "SRC=!SRC:\=/!"
set "WIN=!SRC:/=\!"
if not "!WIN:~1,1!"==":" goto :have_file
echo [ERROR] The file is not inside the learncpp folder: !WIN!
goto :failed
:have_file
if exist "!WIN!" goto :have_exe
echo [ERROR] File not found: !WIN!
goto :failed

rem ---- work out the exe path (same naming rule as the Makefile) ----
:have_exe
for %%F in ("!WIN!") do (
    set "RDIRA=%%~dpF"
)
set "RDIR=!RDIRA:%ROOT%=!"
if exist "!RDIR!main.cpp" goto :dir_program
set "EXE=build\!WIN:.cpp=.exe!"
goto :compile
:dir_program
set "D=!RDIR:~0,-1!"
for %%D in ("!D!") do set "DIRNAME=%%~nxD"
set "EXE=build\!RDIR!!DIRNAME!.exe"

:compile
echo.
echo === Compiling !SRC! ===
set "TARGET=!EXE:\=/!"
mingw32-make "!TARGET!"
if errorlevel 1 goto :failed
if not exist "!EXE!" goto :no_main

echo.
"!EXE!" !ARGS!
set "RC=!errorlevel!"
echo.
if not "!RC!"=="0" echo [Exit code !RC!]
goto :done

:no_main
echo.
echo [NOTE] No main() in this file yet, so only the .o was built.
goto :done

:no_source
echo [ERROR] No .cpp file found under this folder.
goto :failed
:no_compiler
echo [ERROR] g++ not found in PATH. Check your MinGW installation.
goto :failed
:no_make
echo [ERROR] mingw32-make not found in PATH. Check your MinGW installation.

:failed
set "RC=1"
echo.
pause
exit /b !RC!

:done
echo.
pause
exit /b !RC!
