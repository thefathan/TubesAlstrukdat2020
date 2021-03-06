#include <stdio.h>
#include "command.c"
#include "../ADT/boolean.h"
#include "string.h"


int main() {

    int duite = 1000000;
    TabInv toko, invent;
    Stack buildkomp;  
    int i;
    
    toko = MakeList(); // shop, jika beli barang ditransfer ke inventory
    for (i=0; i<5; i++) {
        NamaKomponen NK = {"AMD Ryzen 13 1000GB", 10000, i, 1};
        InsertLast(&toko, NK);
    }

    invent = MakeList(); // inventorymu
    for (i=0; i<3; i++) {
        NamaKomponen NK = {"AMD Bakso 1000GB", 10000, i, 1};
        InsertLast(&invent, NK);
    }


    buildkomp = CreateEmptyStack(); //yg ada di pemasangan komponen
    for (i=0; i<7; i++) {
        Sinfotype input = {"Intel Goreng", 10000, i+1, 1};    
        Push(&buildkomp, input);
    }





    boolean stateProg = true;
    char command[20];
    int pilihan;

    while (stateProg == true) {
        printf("\nENTER COMMAND: ");
        scanf("%s", &command);
        if (strcmp(command, "A") == 0) {
            ADDCOMPONENT(&buildkomp, &invent);
            getchar();
        }
        else if (strcmp(command, "R") == 0) {
            REMOVECOMPONENT(&buildkomp, &invent);
            getchar();
        }
        else if (strcmp(command, "S") == 0) {
            SHOP(&toko, &invent, &duite);
            getchar();
        }

        else if (strcmp(command, "STATUS") == 0) {
            STATUS(&invent, &duite);
            getchar();
        }
        else {
            char opsi[10];
            printf("========================================================\n");
            printf("Apakah anda yakin ingin keluar? (YA/Apapun) ");
            scanf("%s", &opsi);

            int opt = EXIT(opsi);
            boolean Apa;
            if (opt == 1) {
                printf("Anda keluar dari permainan.\n");
                printf("========================================================\n");
                Apa = false;
            } else {
                printf("Silakan lanjutkan.\n");
                printf("========================================================\n");
                Apa = true;
            }
            stateProg = Apa;
        }
    }
}