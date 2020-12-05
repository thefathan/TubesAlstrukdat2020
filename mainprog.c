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
                // sleep(1);
                // printf("|||||||||||||||||||||||||");
                // sleep(1);
                // printf("|||||||||||||||||||");
                // sleep(1);
                // printf("||||||||||||||||||||");
                // sleep(1);
                // printf("|||||||||||||||");
                // sleep(1);
                printf("\n\nLoading complete!\n\n");
                sleep(1);
                printf("Tekan enter untuk melanjutkan.");
                getchar();
                printf("\n");


                // INISIASI VARIABEL (UNTUK STATE GAME YANG AKAN DIMAINKAN)

                int duite = 1000000;
                TabInv toko, invent;
                Stack buildkomp, queuekomp;  
                Queue orderQueue;
                int pilihan, nomorantrian = 1;
                boolean stateProg = true;
                char command[20];
                

                /*  INISIASI LIST TOKO DENGAN FILE EKSTERNAL 
                    ASUMSI AWAL GAME PEMAIN TIDAK PUNYA INVENTORY APA-APA */

                queuekomp = CreateEmptyStack();

                if (nomorantrian == 2) {
                    Sinfotype QK = {"Asus-ROG-Zenith-II-Extreme 1000", 1, 1, 1};
                    Push(&queuekomp, QK);
                    Sinfotype QI = {"AMD-Ryzen-Threadripper-3990X-2.9Ghz-Up-To-4.3Ghz-64-Core 5100", 1, 1, 1};
                    Push(&queuekomp, QI);
                    Sinfotype QJ = {"ADATA-DDR4-XPG-GAMMIX-D30-PC24000-3000MHz-16GB-(2X8GB)-Dual-Channel-AX4U300038G16A-DR30", 1, 1, 1};
                    Push(&queuekomp, QJ);
                    Sinfotype QL = {"CUBE-GAMING-STORM-DUAL-FAN-12CM-ARGB-Universal-Socket", 1, 1, 1};
                    Push(&queuekomp, QL);
                    Sinfotype QM = {"Antec-Premium-Gaming-Case-TORQUE-BLACK-/-WHITE-Alumunium-Panels-Dual-Side-Tempered-Glass", 1, 1, 1};
                    Push(&queuekomp, QM);
                    Sinfotype QN = {"Asus-GeForce-RTX-3090-24GB-GDDR6X-ROG-Strix", 1, 1, 1};
                    Push(&queuekomp, QN);
                    Sinfotype QO = {"Apacer-AS340-120GB-Panther", 1, 1, 1};
                    Push(&queuekomp, QO);
                    Sinfotype QP = {"Asus-ROG-Strix-550W-Fully-Modular-80+-Gold", 1, 1, 1};
                    Push(&queuekomp, QP);
                }

                else if (nomorantrian == 1) {
                    Sinfotype QK = {"AMD", 1, 1, 1};
                    Push(&queuekomp, QK);
                    Sinfotype QI = {"AMD", 1, 1, 1};
                    Push(&queuekomp, QI);
                    Sinfotype QJ = {"AMD", 1, 1, 1};
                    Push(&queuekomp, QJ);
                    Sinfotype QL = {"AMD", 1, 1, 1};
                    Push(&queuekomp, QL);
                    Sinfotype QM = {"AMD", 1, 1, 1};
                    Push(&queuekomp, QM);
                    Sinfotype QN = {"AMD", 1, 1, 1};
                    Push(&queuekomp, QN);
                    Sinfotype QO = {"AMD", 1, 1, 1};
                    Push(&queuekomp, QO);
                    Sinfotype QP = {"AMD", 1, 1, 1};
                    Push(&queuekomp, QP);
                }

                // PrintStack(&queuekomp);

                
                FILE *fp;
                char x;
                char array[115][2000];
                char array2[115][2000];
                char str[100000];
                char* filename = "listkomponen.txt";
                int i = 0, j = 0;
            
                fp = fopen(filename, "r");
                if (fp == NULL){
                    printf("Could not open file %s",filename);
                    return 1;
                }
                while (fgets(str, sizeof(str), fp) != NULL) { 
                    strcpy(array[i],str);
                    i++;
                }
                fclose(fp);

                toko = MakeList(); // shop, jika beli barang ditransfer ke inventory
                invent = MakeList(); // inventorymu
                buildkomp = CreateEmptyStack(); //yg ada di pemasangan komponen
                orderQueue = CreateQueue(200); // untuk queue 

                int harga, tipe, jumlah;
                char namakomponen[100], dtm[150];
                for (int a = 0; a < i; a++) {
                    strcpy(dtm, array[a]);
                    sscanf(dtm, "%s %d %d  %d", namakomponen, &harga, &tipe, &jumlah);
                    NamaKomponen NK = {"dummy", harga, tipe, jumlah};
                    strcpy(NK.Nama, namakomponen);
                    InsertLast(&toko, NK);
                }

                ElTypeQueue Y = {{" ", 0, 0, 0}, 0, 0, 0};
                Enqueue(&orderQueue,Y);
                for (int i = 0; i < 20; i++) {                                  // inisiasi orderQueue tanpa eksternal dan random
                    ElTypeQueue X = {{"AMD Zotac", 200, 2, 1}, i+1, i+20, rand()};
                    Enqueue(&orderQueue,X);
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
                        CHECKORDER(&orderQueue, &queuekomp);
                        getchar();
                    }


                    // COMMAND STATUS -------------------------------------------------------------------------
                    else if (strcmp(command, "STATUS") == 0) {
                        STATUS(&invent, &orderQueue, &duite);
                        getchar();
                    }


                    // COMMAND STARTBUILD ----------------------------------------------------------------------
                    else if (strcmp(command, "STARTBUILD") == 0) {
                        STARTBUILD(&orderQueue);
                        getchar();
                    }


                    // COMMAND FINISHBUILD --------------------------------------------------------------------
                    else if (strcmp(command, "FINISHBUILD") == 0) {
                        FINISHBUILD(&orderQueue, &buildkomp, &queuekomp, &nomorantrian, &duite);
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