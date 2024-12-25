#include "game.h"

void display_menu(t_game *game) {
    printf("\nMAIN MENU:\n\n");
    printf("Height: %u\n", game->grid_height);
    printf("Length: %u\n", game->grid_length);
    printf("Density: %u\n", game->density);
    printf("\nUse D-PAD to adjust, START to continue\n");
}

void menu(t_game *game)
{
    UINT8 last_grid_height;
    UINT8 last_grid_length;
    UINT8 last_density;
    
    last_grid_height = game->grid_height;
    last_grid_length = game->grid_length;
    last_density = game->density;
    display_menu(game);  // First menu display

    while(1)
    {
        UINT8 input;
        
        input = joypad();
        // Button press listening
        if (input & J_UP && game->grid_height < 15) {
            game->grid_height++;
        } else if (input & J_DOWN && game->grid_height > 5) {
            game->grid_height--;
        } else if (input & J_LEFT && game->grid_length > 5) {
            game->grid_length--;
        } else if (input & J_RIGHT && game->grid_length < 15) {
            game->grid_length++;
        } else if (input & J_A && game->density < 5) {
            game->density++;
        } else if (input & J_B && game->density > 1) {
            game->density--;
        } else if (input & J_START) {
            return;
        }
        // if something changed, redisplay menu and change values
        if (game->grid_height != last_grid_height || game->grid_length != last_grid_length || game->density != last_density) {
            printf("\n\n");
            display_menu(game);
            // Update the last known values
            last_grid_height = game->grid_height;
            last_grid_length = game->grid_length;
            last_density = game->density;
        }
        // Wait the end of inputs or/and the vertical scrolling before continuing.
        wait_vbl_done();
    }
}
