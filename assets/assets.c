/* File : assets.h */
/* Definisi Modul print aset-aset ASCII Art */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_LEN 128

// $ ********** IMPLEMENTASI **********

void print_image(char *filename) {
    FILE *fptr = NULL;

    if ((fptr = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "error opening %s\n", filename);
    }
    char read_string[MAX_LEN];
    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s", read_string);
    fclose(fptr);
}

void MainProgram() {
    print_image("assets//img_mainprogram.txt");
}
void MainMenu() {
    print_image("assets//img_mainmenu.txt");
}
void Credits() {
    print_image("assets//img_credits.txt");
}
void Loading() {
    print_image("assets//img_loading.txt");
}
void Command() {
    print_image("assets//img_commands.txt");
}
void Invalid() {
    print_image("assets//img_invalidstatement.txt");
    getchar();
}
void Quit() {
    print_image("assets//img_quit.txt");
}
void Overview() {
    print_image("assets//img_overview.txt");
}
void P2Wins() {
    print_image("assets//img_p2wins.txt");
}
void QuitImg(){
    print_image("assets//img_quit.txt");
}