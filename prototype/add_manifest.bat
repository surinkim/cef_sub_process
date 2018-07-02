@echo off
set platform=%1
set config=%2

echo ----------------------------------------
echo Add Manifest
echo ----------------------------------------
echo   platform : %platform%
echo   config : %config%
echo ----------------------------------------

setlocal
mt.exe -nologo -manifest "..\..\cef_3_3325_1756_g6d8faa4\manifest\compatibility.manifest" -outputresource:"..\bin\%platform%\%config%\sub.exe";#1
if %errorlevel% neq 0 goto :cmEnd
:cmEnd
endlocal & call :cmErrorLevel %errorlevel% & goto :cmDone
:cmErrorLevel
exit /b %1
:cmDone
if %errorlevel% neq 0 goto :VCEnd