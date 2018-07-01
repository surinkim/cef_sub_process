@echo off

set platform=%1
set config=%2

echo -------------------------------------
echo Copy bin(changed and new files only)
echo   platform : %platform%
echo   config : %config%
echo -------------------------------------

XCOPY ..\..\cef_3_3325_1756_g6d8faa4\bin\%platform%\%config%\* ..\bin\%platform%\%config%\* /s /d
XCOPY ..\..\cef_3_3325_1756_g6d8faa4\Resources\%platform%\* ..\bin\%platform%\%config%\* /s /d