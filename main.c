#include "game.h"

void    endgame(void)
{
    printf("\nPress START to retry\n");
    wait_vbl_done();
    while(1)
    {
        UINT8 input;
        
        input = joypad();
        if (input & J_START)
        {
            __asm
                jp 0x0100;
            __endasm;
        }
    }
}

void main() {
    t_game game;
    game.grid_height = 10;
    game.grid_length = 10;
    game.density = 3;
    display_title_screen();
    menu(&game);
    start_game(&game);
    delay(1000);
    endgame();
}