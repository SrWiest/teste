@echo off
setlocal EnabledelayedExpansion

:: ----------------------------------------------
:: Simple script to build a PKG (by CaptainCPS-X)
:: ----------------------------------------------

:: Change these for your application / manual...
set CID=CUSTOM-INSTALLER_00-0000000000000000

for /D %%A in (4.89*) do (
set nm=%%A
make_package_custom.exe --contentid %CID% ./%%A/ ps3hen_!nm:.=!.pkg
echo | ps3xploit_rifgen_edatresign ps3hen_!nm:.=!.pkg ps3 >> NUL
del /q ps3hen_!nm:.=!.pkg
if exist "ps3hen_!nm:.=!.pkg" echo !nm! PKG done
echo.
)
pause