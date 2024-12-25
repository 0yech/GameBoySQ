#include "game.h"

void free_grid(char **grid)
{
    UINT8 i;

    i = 0;
    if (!grid)
        return;
    while (grid[i] != NULL)
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}

void    print_final(t_game *game, UINT8 x, UINT8 y, UINT8 big)
{
    UINT8 i;
    UINT8 j;

    j = 0;
    i = 0;
    while (i < big)
    {
        j = 0;
        while (j < big)
        {
            game->grid[y + i][x + j] = 'X';
            j++;
        }
        i++;
    }
    i = 0;
    display_grid(game->grid_height, game->grid_length, game);
}

UINT8     recurchecker(UINT8 x, UINT8 y, UINT8 size, t_game *game) {
    UINT8 i;
    UINT8 j;

    i = 0;
    if (x + size > game->grid_length || y + size > game->grid_height)
        return 0;

    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (game->grid[y + i][x + j] != '.')
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

void    solve_game(t_game *game) {
    UINT8 x = 0;
    UINT8 y = 0;
    t_solver box;

    box.xpos = 0;
    box.ypos = 0;
    box.size = 0;
    box.biggest = 0;
    while (y < game->grid_height)
    {
        x = 0;
        while (x < game->grid_length)
        {
            if (game->grid[y][x] == '.')
            {
                box.size = 1;
                while (recurchecker(x, y, box.size, game)) // Increase box size when 1 is returned
                    box.size++;
                if (box.size - 1 > box.biggest)
                {
                    box.xpos = x;
                    box.ypos = y;
                    box.biggest = box.size - 1;
                }
            }
            x++;
        }
        y++;
    }
    delay(1000);
    printf("\nBiggest : %d", box.biggest);
    printf("\nxpos : %d", box.xpos);
    printf("\nypos : %d", box.ypos);
    printf("\nlen : %d", game->grid_length);
    printf("\nhei : %d\n", game->grid_height);
    delay(3000);
    print_final(game, box.xpos, box.ypos, box.biggest);
    wait_vbl_done();
}
