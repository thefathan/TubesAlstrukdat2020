#include <stdio.h>
#include <unistd.h>
#include "assets/assets.c"
#include "ADT/boolean.h"
#include "string.h"
#include "command/command.c"



// $ ***** Variable Global *****
char menu[100];
boolean Exit;       // = false;
boolean ExitMenu;   // = false;
// boolean EndTurn;    // = false;
// boolean AksiValid;	// = true


int main() {
    do {
        Exit = false;
        puts("");
        MainProgram();
        printf("\n");
        do {
            ExitMenu = false;
            MainMenu();
            int idxMenu = 0;
            do {
                scanf("%c", menu + idxMenu);
            } while (menu[idxMenu++] != '\n');
            menu[--idxMenu] = '\0';

                // ######### TUTORIAL ########################################
            if (strcmp(menu,"OVERVIEW") == 0) {
                printf("\n");
                puts("");
                printf("Tekan enter untuk lanjut.\n");
                getchar();
                puts("");
                Overview();
                sleep(1);
                puts("");;
                printf("\nTekan enter lagi untuk kembali.\n");
                getchar();
                puts("");
                ExitMenu = true;

            }   // ######### CREDITS ######################################
            else if (strcmp(menu, "CREDITS") == 0) {
                puts("");
                Credits();
                getchar();
                ExitMenu = true;

            }   // ######### QUIT ########################################
            else if (strcmp(menu, "QUIT") == 0) {
                Quit();
                ExitMenu = true;
                Exit = true;
            }
            // ######### PLAY ############ PROGRAM UTAMANYA DIBAWAH INI #######################################################
            else if (strcmp(menu, "PLAY") == 0) {
                puts("");
                Loading();
                sleep(1);
                printf("|||||||||||||||||||||||||");
                sleep(1);
                printf("|||||||||||||||||||");
                sleep(1);
                printf("||||||||||||||||||||");
                sleep(1);
                printf("|||||||||||||||");
                sleep(1);
                printf("\n\nLoading complete!\n\n");
                sleep(1);
                printf("Tekan enter untuk melanjutkan.");
                getchar();
                printf("\n");


                // INISIASI VARIABEL (UNTUK STATE GAME YANG AKAN DIMAINKAN)

                int duite = 1000000;
                TabInv toko, invent;
                Stack buildkomp;  
                int i, pilihan;
                boolean stateProg = true;
                char command[20];
                

                /* COBA INISIASI LIST DAN STACK BUKAN DENGAN FILE EKSTERNAL */

                toko = MakeList(); // shop, jika beli barang ditransfer ke inventory
                for (i=0; i<5; i++) {
                    NamaKomponen NK = {"AMD Ryzen 13 1000GB", 10000, i};
                    InsertLast(&toko, NK);
                }
                invent = MakeList(); // inventorymu
                for (i=0; i<3; i++) {
                    NamaKomponen NK = {"AMD Bakso 1000GB", 10000, i};
                    InsertLast(&invent, NK);
                }
                buildkomp = CreateEmptyStack(); //yg ada di pemasangan komponen
                for (i=0; i<7; i++) {
                    Sinfotype input = {"Intel Goreng", 10000, i+1};    
                    Push(&buildkomp, input);
                }


                while (stateProg == true) {
                    Command();
                    scanf("%s", &command);
                    printf("\n");


                    // COMMAND ADDCOMPONENT --------------------------------------------------------------
                    if (strcmp(command, "ADDCOMPONENT") == 0) {
                        ADDCOMPONENT(&buildkomp, &invent);
                        getchar();
                    }


                    // COMMAND REMOVECOMPONENT -------------------------------------------------------------
                    else if (strcmp(command, "REMOVECOMPONENT") == 0) {
                        REMOVECOMPONENT(&buildkomp, &invent);
                        getchar();
                    }


                    // COMMAND SHOP ------------------------------------------------------------------------
                    else if (strcmp(command, "SHOP") == 0) {
                        SHOP(&toko, &invent, &duite);
                        getchar();
                    }


                    // COMMAND EXIT -------------------------------------------------------------------------
                    else if (strcmp(command, "EXIT") == 0) {
                        char opsi[10];
                        printf("========================================================\n");
                        printf("Apakah anda yakin ingin keluar? (YA/Apapun) ");
                        scanf("%s", &opsi);

                        int opt = EXIT(opsi);
                        boolean Apa;
                        if (opt == 1) {
                            printf("Anda keluar dari permainan.\n");
                            printf("========================================================");
                            Apa = false;
                        } else {
                            printf("Silakan lanjutkan.\n");
                            printf("========================================================\n");
                            Apa = true;
                        }
                        stateProg = Apa;
                    }


                    // COMMAND MOVE -------------------------------------------------------------------------
                    else if (strcmp(command, "MOVE") == 0) {
                        MOVE();
                        getchar();
                    }


                    // COMMAND CHECKORDER ---------------------------------------------------------------------
                    else if (strcmp(command, "CHECKORDER") == 0) {
                        CHECKORDER();
                        getchar();
                    }


                    // COMMAND STATUS -------------------------------------------------------------------------
                    else if (strcmp(command, "STATUS") == 0) {
                        STATUS();
                        getchar();
                    }


                    // COMMAND STARTBUILD ----------------------------------------------------------------------
                    else if (strcmp(command, "STARTBUILD") == 0) {
                        STARTBUILD();
                        getchar();
                    }


                    // COMMAND FINISHBUILD --------------------------------------------------------------------
                    else if (strcmp(command, "FINISHBUILD") == 0) {
                        FINISHBUILD();
                        getchar();
                    }


                     // COMMAND DELIVER -----------------------------------------------------------------------
                    else if (strcmp(command, "DELIVER") == 0) {
                        DELIVER();
                        getchar();
                    }


                    // COMMAND SAVE ----------------------------------------------------------------------------
                    else if (strcmp(command, "SAVE") == 0) {
                        SAVE();
                        getchar();
                    }


                    // COMMAND END_DAY ------------------------------------------------------------------------
                    else if (strcmp(command, "END_DAY") == 0) {
                        END_DAY();
                        getchar();
                    }


                    // COMMAND MAP -----------------------------------------------------------------------------
                    else if (strcmp(command, "MAP") == 0) {
                        MAP();
                        getchar();
                    }


                    // JIKA COMMAND YANG DIMASUKKAN SELAIN DAFTAR COMMAND MAKA AKAN MENGULANG ------------------
                    else {
                        Invalid();
                        getchar();
                        puts("");
                    }
                }
                getchar();
                ExitMenu = true;
            }


            // ########## JIKA MENU UTAMA SALAH MEMASUKKANNYA (MENGULANG) ##############################
            else {
                Invalid();
                puts("");
            }

        } while (!ExitMenu);
        ExitMenu = false;
    } while (!Exit);
    return 0;
}