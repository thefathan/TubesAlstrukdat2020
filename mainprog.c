#include <stdio.h>
#include <unistd.h>
#include "assets/assets.c"
#include "ADT/boolean.h"
#include "string.h"
#include "command/command.c"



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
        MainProgram();
        printf("\n");
        do {
            ExitMenu = false;
            MainMenu();
            // * Lakukan Input dengan 'mesinkata'
            int idxMenu = 0;
            do {
                scanf("%c", menu + idxMenu);
            } while (menu[idxMenu++] != '\n');
            menu[--idxMenu] = '\0';

                // $ ######### TUTORIAL ########
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

            }   // $ ######### CREDITS ########
            else if (strcmp(menu, "CREDITS") == 0) {
                puts("");
                Credits();
                getchar();
                ExitMenu = true;

            }   // $ ######### QUIT ########
            else if (strcmp(menu, "QUIT") == 0) {
                Quit();
                ExitMenu = true;
                Exit = true;
            }
            // ######### PLAY #################################################################################
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

                    if (strcmp(command, "ADDCOMPONENT") == 0) {      // COMMAND ADDCOMPONENT
                        ADDCOMPONENT(&buildkomp, &invent);
                        getchar();
                    }



                    else if (strcmp(command, "REMOVECOMPONENT") == 0) {     // COMMAND REMOVECOMPONENT
                        REMOVECOMPONENT(&buildkomp);
                        getchar();
                    }



                    else if (strcmp(command, "SHOP") == 0) {            // COMMAND SHOP
                        SHOP(&toko, &invent, &duite);
                        getchar();
                    }



                    else if (strcmp(command, "EXIT") == 0) {            // COMMAND EXIT
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



                    else if (strcmp(command, "MOVE") == 0) {                // COMMAND MOVE
                        MOVE();
                        getchar();
                    }



                    else if (strcmp(command, "CHECKORDER") == 0) {          // COMMAND CHECKORDER
                        CHECKORDER();
                        getchar();
                    }



                    else if (strcmp(command, "STATUS") == 0) {              // COMMAND STATUS
                        STATUS();
                        getchar();
                    }



                    else if (strcmp(command, "STARTBUILD") == 0) {          // COMMAND STARTBUILD
                        STARTBUILD();
                        getchar();
                    }



                    else if (strcmp(command, "FINISHBUILD") == 0) {         // COMMAND FINISHBUILD
                        FINISHBUILD();
                        getchar();
                    }



                    else if (strcmp(command, "DELIVER") == 0) {             // COMMAND DELIVER
                        DELIVER();
                        getchar();
                    }



                    else if (strcmp(command, "SAVE") == 0) {                // COMMAND SAVE
                        SAVE();
                        getchar();
                    }



                    else if (strcmp(command, "END_DAY") == 0) {             // COMMAND END_DAY
                        END_DAY();
                        getchar();
                    }



                    else if (strcmp(command, "MAP") == 0) {                 // COMMAND MAP
                        MAP();
                        getchar();
                    }


                    else {                     // JIKA COMMAND YANG DIMASUKKAN SELAIN DAFTAR COMMAND MAKA AKAN MENGULANG
                        Invalid();
                        getchar();
                        puts("");
                    }
                }
                getchar();
                ExitMenu = true;
            }

            else {
                Invalid();
                puts("");
            }

        } while (!ExitMenu);
        ExitMenu = false;
    } while (!Exit);
    return 0;
}

// void COMMAND(){
//     char com[20];

//     printf ("ENTER COMMAND : ");
//     scanf ("%s", &com);
    
//     if (strcmp(com, "MOV") == 0){
//         MOVE();
//     }else if (strcmp(com, 'STATUS') == 0){
//         STATUS();
//     }else if (strcmp(com, 'CHECKORDER') == 0){
//         CHECKORDER();
//     }else if (strcmp(com, 'STARTBUILD') == 0){
//         STARTBUILD();
//     }else if (strcmp(com, 'FINISHBUILD') == 0){
//         FINISHBUILD();
//     }else if (strcmp(com, 'ADDCOMPONENT') == 0){
//         ADDCOMPONENT();
//     }else if (strcmp(com, 'REMOVECOMPONENT') == 0){
//         REMOVECOMPONENT();
//     }else if (strcmp(com, 'SHOP') == 0){
//         SHOP();
//     }else if (strcmp(com, 'DELIVER') == 0){
//         DELIVER();
//     }else if (strcmp(com, 'END_DAY') == 0){
//         END_DAY();
//     }else if (strcmp(com, 'SAVE') == 0){
//         SAVE();
//     }else if (strcmp(com, 'MAP') == 0){
//         MAP();
//     }else if (strcmp(com, 'EXIT') == 0){
//         EXIT();
//     }else {
//         printf("ENTER COMMAND : ");
//         scanf("%s", &com);
//     }
//     return 0;
// }