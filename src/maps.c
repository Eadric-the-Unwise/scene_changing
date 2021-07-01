#include "maps.h"

#include "../res/maps/cellar_2_map.h"
#include "../res/maps/cellar_2_tiles.h"
#include "../res/maps/cellar_map.h"
#include "../res/maps/cellar_tiles.h"
#include "../res/maps/house_map.h"
#include "../res/maps/house_tiles.h"
#include "../res/maps/submap_map.h"
#include "../res/maps/submap_tiles.h"

Map map[4] =
    {
        {.tile_data = OFFSET(SUBMAP_TILE_DATA),
         .tile_bank = BANK(SUBMAP_TILE_DATA),
         .map_data = OFFSET(SUBMAP_MAP_DATA),
         .map_bank = BANK(SUBMAP_MAP_DATA),
         .width = SUBMAP_MAP_WIDTH,
         .height = SUBMAP_MAP_HEIGHT,
         .is_submap = TRUE},

        {.tile_data = OFFSET(HOUSE_TILE_DATA),
         .tile_bank = BANK(HOUSE_TILE_DATA),
         .map_data = OFFSET(HOUSE_MAP_DATA),
         .map_bank = BANK(HOUSE_MAP_DATA),
         .width = HOUSE_MAP_WIDTH,
         .height = HOUSE_MAP_HEIGHT,
         .is_submap = FALSE},

        {.tile_data = OFFSET(CELLAR_TILE_DATA),
         .tile_bank = BANK(CELLAR_TILE_DATA),
         .map_data = OFFSET(CELLAR_MAP_DATA),
         .map_bank = BANK(CELLAR_MAP_DATA),
         .width = CELLAR_MAP_WIDTH,
         .height = CELLAR_MAP_HEIGHT,
         .is_submap = FALSE},

        {.tile_data = OFFSET(CELLAR_2_TILE_DATA),
         .tile_bank = BANK(CELLAR_2_TILE_DATA),
         .map_data = OFFSET(CELLAR_2_MAP_DATA),
         .map_bank = BANK(CELLAR_2_MAP_DATA),
         .width = CELLAR_2_MAP_WIDTH,
         .height = CELLAR_2_MAP_HEIGHT,
         .is_submap = FALSE}

};

void set_banked_bkg_data(UINT8 start, UINT8 count, const void *tile_data, UINT8 bank)
#ifndef __INTELLISENSE__
    NONBANKED
#endif
{
    UINT8 __save = _current_bank;
    SWITCH_ROM_MBC1(bank);
    set_bkg_data(start, count, tile_data);
    SWITCH_ROM_MBC1(__save);
}

void set_banked_bkg_tiles(UINT8 x, UINT8 y, UINT8 w, UINT8 h, const void *map_data, UINT8 bank)
#ifndef __INTELLISENSE__
    NONBANKED
#endif
{
    UINT8 __save = _current_bank;
    SWITCH_ROM_MBC1(bank);
    set_bkg_tiles(x, y, w, h, map_data);
    SWITCH_ROM_MBC1(__save);
}

void set_banked_bkg_submap(UINT8 x, UINT8 y, UINT8 w, UINT8 h, const void *map_data, UINT8 map_w, UINT8 bank)
#ifndef __INTELLISENSE__
    NONBANKED
#endif
{
    UINT8 __save = _current_bank;
    SWITCH_ROM_MBC1(bank);
    set_bkg_submap(x, y, w, h, map_data, map_w);
    SWITCH_ROM_MBC1(__save);
}

void set_level(Map *map) {
    // called when the level is changed.
    // load tiles and map data.
    DISPLAY_OFF;
    set_banked_bkg_data(0, 255u, map->tile_data, map->tile_bank);
    if (map->is_submap) {
        set_banked_bkg_submap(0, 0, 32u, 32u, map->map_data, map->width, map->map_bank);
    } else {
        set_banked_bkg_tiles(0, 0, map->width, map->height, map->map_data, map->map_bank);
    }
    DISPLAY_ON;
}