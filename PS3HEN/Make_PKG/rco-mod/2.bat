@echo off
setlocal enabledelayedexpansion
set pt=Rcomage\

!pt!rcomage.exe dump .\8efC\explore_plugin_full.rco .\8efC2\efc.xml --RESDIR .\8efC2\ --text txt --images img 
rem !pt!rcomage.exe compile .\8efC\ef.xml .\8efC\ef.rco --pack-hdr zlib