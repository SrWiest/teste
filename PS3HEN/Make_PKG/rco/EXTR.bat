@echo off

cd Rcomage
for %%i in (F:\rco\1\*.rco) do (
md %%~pi%%~ni
rcomage.exe dump %%i %%~pi%%~ni.xml --RESDIR %%~pi%%~ni --images - --sounds -
)