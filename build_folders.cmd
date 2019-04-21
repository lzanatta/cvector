@echo off

if [%1]==[] goto :eof
if [%1]==[make] goto :make
if [%1]==[clean] goto :clean

:: make build folders for object files and .exe output
:make
if not exist "obj\src\" mkdir obj\src\
if not exist "obj\test\" mkdir obj\test\
if not exist "bin\" mkdir bin\
goto :eof

:: clean compilation files (just delete folders) for a clean build
:clean
if exist "obj\" rmdir obj\ /S /Q
if exist "bin\" rmdir bin\ /S /Q
goto :eof
