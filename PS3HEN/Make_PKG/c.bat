@echo off
setlocal enabledelayedexpansion

for %%A in (ps3hen_4??.pkg_signed.pkg) do (
set n=%%A
set v=!n:~8,2!
xcopy /Y !n! D:\PSPX\guthub\nikolaevich23.github.io\alt\4.!v!\latest_rus_sign.pkg
)
