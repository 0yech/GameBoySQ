#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include <time.h>

#define MAX_HEIGHT 15
#define MAX_LENGTH 15

UINT8 rand_num(UINT8 max)
{
    return DIV_REG % max;
}

void generate_grid(t_game *game)
{
    UINT8 i;
    UINT8 j;

    i = 0;
    while (i < game->grid_height)
    {
        j = 0;
        while (j < game->grid_length)
        {
            if (rand_num(50) < game->density)
                game->grid[i][j] = 'o';
            else
                game->grid[i][j] = '.';
            j++;
        }
        i++;
    }
}

void display_grid(UINT8 height, UINT8 length, t_game *game)
{
    UINT8 i;
    UINT8 j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < length)
        {
            printf("%c", game->grid[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    wait_vbl_done();
}

void start_game(t_game *game)
{
    UINT8 i;

    i = 0;
    game->grid = (char **)malloc(sizeof(char *) * game->grid_height);
    while (i < game->grid_height)
    {
        game->grid[i] = (char *)malloc(sizeof(char) * game->grid_length);
        i++;
    }
    generate_grid(game);
    printf("\nGenerated Grid:\n");
    display_grid(game->grid_height, game->grid_length, game);
    solve_game(game);
}