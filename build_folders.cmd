@ECHO OFF

IF [%1]==[] GOTO:EOF
IF [%1]==[make] GOTO:MAKE
IF [%1]==[clean] GOTO:CLEAN

:MAKE
IF not exist "obj\release\src\" mkdir obj\release\src\
IF not exist "obj\release\test\" mkdir obj\release\test\
IF not exist "bin\" mkdir bin\
GOTO:EOF

:CLEAN
IF exist "obj\" rmdir obj\ /S /Q
IF exist "bin\" rmdir bin\ /S /Q
GOTO:EOF
