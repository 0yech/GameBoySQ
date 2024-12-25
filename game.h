#ifndef GAME_H
#define GAME_H

#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct s_game
{
    UINT8 grid_height;
    UINT8 grid_length;
    UINT8 density;
    char **grid;
}   t_game;

typedef struct s_solver
{
    UINT8 size;
    UINT8 biggest;
    UINT8 xpos;
    UINT8 ypos;
}   t_solver;

void    solve_game(t_game *game);

void free_grid(char **grid);


void display_menu(t_game *game);
void menu(t_game *game);

void display_title_screen();

void generate_grid(t_game *game);
void display_grid(UINT8 height, UINT8 length, t_game *game);
void start_game(t_game *game);

#endif
