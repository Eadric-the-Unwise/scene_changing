call .\clean.bat

@echo off
@set GBDK=..\..\..\gbdk\
%GBDK%\bin\lcc.exe -autobank -Wb-ext=.rel -Wb-v -Wl-yt0x1B -Wl-yoA -Wl-ya4 -o actors_handling.gb^
 src\*.c res\tiles\*.c
 


