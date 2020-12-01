#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "string.h"


Stack BuildKomponen;
Sinfotype isiStack; 
NamaKomponen isiInventory;
TabInv Inventory, Toko;

void MOVE() {

}

void STATUS() {

}

void CHECKORDER() {

}

void STARTBUILD() {

}

void FINISHBUILD() {

}

void ADDCOMPONENT() {
    printf("Komponen yang telah terpasang: \n");
    PrintStack(&BuildKomponen);
    printf("Komponen yang tersedia: \n");
    PrintList(Inventory);
    Push(&BuildKomponen, isiStack);
    getchar();
}

void REMOVECOMPONENT() {
    Pop(&BuildKomponen, &isiStack);
    getchar();
}

void SHOP() {

}

void DELIVER() {

}

void END_DAY() {

}

void SAVE() {

}

void MAP() {

}

void EXIT() {
    
}