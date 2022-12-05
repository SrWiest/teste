@echo off
setlocal enabledelayedexpansion

for %%f in (*.gim) do (
set /a n1=0
for /f "tokens=*" %%m in ('CertUtil -hashfile %%f MD5') do (
set /a n1+=1 && if !n1!==2 set hash=%%m && set MD5=!hash: =!
)
echo %%f !MD5!
)
