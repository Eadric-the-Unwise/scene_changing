#include <gb/gb.h>

#define __BANK_PREFIX(A) __bank_##A
#define BANK(A) (UINT8) & (__BANK_PREFIX(A))
#define __SIZE_PREFIX(A) __size_##A
#define SIZE(A) (UWORD) & (__SIZE_PREFIX(A))
#define OFFSET(A) (void *)&(A)

#define MAP_FIXED = 1
#define MAP_SUBMAP = 2

#define SUBMAP 0
#define HOUSE 1
#define CELLAR 2
#define CELLAR_2 3

typedef struct Map {
    const void *tile_data;
    UINT8 tile_bank;

    const void *map_data;
    UINT8 map_bank;

    UINT8 width;
    UINT8 height;

    UBYTE is_submap;
} Map;

extern struct Map map[4];

void set_banked_bkg_data(UINT8 start, UINT8 count, const void *tile_data, UINT8 bank);
void set_banked_bkg_tiles(UINT8 x, UINT8 y, UINT8 w, UINT8 h, const void *map_data, UINT8 bank);
void set_banked_bkg_submap(UINT8 x, UINT8 y, UINT8 w, UINT8 h, const void *map_data, UINT8 map_w, UINT8 bank);
void set_level(Map *map);