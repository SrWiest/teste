@echo off
setlocal enabledelayedexpansion

for %%A in (ps3hen_48?.pkg_signed.pkg) do (
set n=%%A
set v=!n:~9,1!
xcopy /Y !n! E:\PSPX\nikolaevich23.github.io.git\trunk\alt\4.8!v!\latest_rus_sign.pkg
)
