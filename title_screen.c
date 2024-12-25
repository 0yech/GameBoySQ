#include "game.h"

void display_title_screen() {
    printf("\n");
    printf("____________________");
    printf("\n");
    printf("     :     ::::\n");
    printf("    #  +  +:  +:\n");
    printf("   #   #     +#\n");
    printf("   #+#+#    +#\n");
    printf("       #   #+\n"); 
    printf("       #  ####.fr\n");
    printf("____________________");
    printf("\n");
    printf("     GameBoySQ       \n");
    printf("      by nrey        ");
    
    printf("\n\nPress START to continue...");
    waitpad(J_START);
    printf("\nLoading Menu...\n\n\n\n\n\n\n\n\n\n");
}
