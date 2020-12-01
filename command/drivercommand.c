#include <stdio.h>
#include "command.c"
#include "../ADT/boolean.h"
#include "string.h"


int main() {

    int duite = 1000000;
    TabInv toko, invent;
    Stack buildkomp;  
    int i;
    
    toko = MakeList();
    for (i=0; i<5; i++) {
        NamaKomponen NK = {"AMD Ryzen 13 1000GB", 10000, i};
        InsertLast(&toko, NK);
    }

    invent = MakeList();
    for (i=0; i<3; i++) {
        NamaKomponen NK = {"AMD Bakso 1000GB", 10000, i};
        InsertLast(&invent, NK);
    }


    buildkomp = CreateEmptyStack();
    for (i=0; i<2; i++) {
        Sinfotype input = {"Intel Goreng", 10000, i+1};    
        Push(&buildkomp, input);
    }





    boolean stateProg = true;
    char command[20];
    int pilihan;

    while (stateProg == true) {
        printf("enter command: ");
        scanf("%s", &command);
        printf("%s\n", command);
        if (strcmp(command, "A") == 0) {
            printf("void addcomp\n");
            ADDCOMPONENT(buildkomp, invent);
            getchar();
        }
        else if (strcmp(command, "R") == 0) {
            printf("void removecomp\n");
            REMOVECOMPONENT(buildkomp);
            getchar();
        }
        else if (strcmp(command, "S") == 0) {
            printf("void shop\n");
            SHOP(toko, invent, duite);
            getchar();
        }
        else {
            stateProg = false;
        }
    }
}