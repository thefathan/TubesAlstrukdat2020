#ifndef command_H
#define command_H


#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/List/list.c"
#include "../ADT/Stack/stack.c"


// Belum ada parameter prosedur di command.
// Silakan dilanjut disini




void MOVE();

void STATUS();

void CHECKORDER();

void STARTBUILD();

void FINISHBUILD();

void ADDCOMPONENT(Stack *BuildKomponen, TabInv *Inventory);

void REMOVECOMPONENT(Stack *BuildKomponen, TabInv *Inventory);

void SHOP(TabInv *Toko, TabInv *Inventory, int *duitPemain);

void DELIVER();

void END_DAY();

void SAVE();

void MAP();

int EXIT(char *opsiKeluar);


#endif