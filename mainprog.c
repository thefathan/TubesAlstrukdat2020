#include <stdio.h>
#include <unistd.h>
#include "ADT/boolean.h"
#include "string.h"



// $ ***** Variables *****
char menu[100];
boolean Exit;       // = false;
boolean ExitMenu;   // = false;
boolean EndTurn;    // = false;
boolean AksiValid;	// = true


int main() {
    do {
        Exit = false;
        puts("");
        printf("MENDING RAKIR PC!\n");
        do {
            ExitMenu = false;
            printf("MENU UTAMA: TUTORIAL, QUIT, CREDITS, PLAY <== ketikkan salah satu dr tulisan tsb.\n");
            // * Lakukan Input dengan 'mesinkata'
            int idxMenu = 0;
            do {
                scanf("%c", menu + idxMenu);
            } while (menu[idxMenu++] != '\n');
            menu[--idxMenu] = '\0';

                // $ ######### TUTORIAL ########
            if (strcmp(menu,"TUTORIAL") == 0) {
                printf("\n");
                // todo Tutorial1();
                puts("");
                printf("#TUT1 PLACEHOLDER#\n");
                getchar();
                puts("");
                // todo Tutorial2();
                printf("#TUT2 PLACEHOLDER#\n");
                getchar();
                puts("");
                ExitMenu = true;

            }   // $ ######### CREDITS ########
            else if (strcmp(menu, "CREDITS") == 0) {
                puts("");
                printf("ini credit cok\n");
                printf("\n");
                printf("Press enter to go back to the main menu...");
                getchar();
                ExitMenu = true;

            }   // $ ######### QUIT ########
            else if (strcmp(menu, "QUIT") == 0) {
                printf("sayonara\n");
                ExitMenu = true;
                Exit = true;
            }
            // ######### PLAY #########
            else if (strcmp(menu, "PLAY") == 0) {
                puts("");
                printf("\n              Loading game...\n\n");
                sleep(1);
                printf("              ||");
                sleep(1);
                printf("|||");
                sleep(1);
                printf("|||");
                sleep(1);
                printf("|||||");
                sleep(1);
                printf("||||||");
                sleep(1);
                printf("||||||||");
                sleep(1);
                printf("|||");
                sleep(1);
                printf("|||||\n\n");
                sleep(1);
                printf("              Loading complete!\n\n");
                sleep(1);
                printf("              Tekan enter untuk melanjutkan.\n\n");
                sleep(1);
                printf("              Programnya belum ada isinya cuy aokwokowakowa. enter lagi sana.\n\n");
                puts("");
                getchar();
                ExitMenu = true;
            }

            else {
                printf("invalid, klik enter lagi\n");
                getchar();
            }

        } while (!ExitMenu);
        ExitMenu = false;
    } while (!Exit);
    return 0;
}