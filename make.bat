call .\clean.bat

@echo off
@set GBDK=..\..\..\gbdk\
%GBDK%\bin\lcc.exe -autobank -Wb-ext=.rel -Wb-v -Wl-yt0x1B -Wl-yo256 -Wl-ya4 -o scene_changing.gb src\main.c src\maps.c^
 res\maps\submap_map.c res\maps\submap_tiles.c^
  res\maps\house_map.c res\maps\house_tiles.c^
   res\maps\cellar_map.c res\maps\cellar_tiles.c^
    res\maps\cellar_2_map.c res\maps\cellar_2_tiles.c
 


