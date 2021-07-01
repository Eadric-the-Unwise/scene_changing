#include <gb/gb.h>

#include "maps.h"

UINT8 joy;

void main() {
    BGP_REG = 0x1B;
    OBP0_REG = 0xE4;
    OBP1_REG = 0xE1;
    DISPLAY_OFF;
    SHOW_BKG;

    set_level(&map[0]);

    DISPLAY_ON;

    while (TRUE) {
        joy = joypad();

        if (joy & J_SELECT) {
            set_level(&map[0]);
        } else if (joy & J_START) {
            set_level(&map[1]);
        } else if (joy & J_A) {
            set_level(&map[2]);
        } else if (joy & J_B) {
            set_level(&map[3]);
        }

        wait_vbl_done();
    }
}