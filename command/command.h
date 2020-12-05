#ifndef command_H
#define command_H


#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/List/list.c"
#include "../ADT/Stack/stack.c"
#include "../ADT/Queue/circular_queue.c"

// Belum ada parameter prosedur di command.
// Silakan dilanjut disini




void MOVE();

void STATUS(TabInv *Inventory, Queue *Q, int *duitPemain);

void CHECKORDER(Queue *Q, Stack *QS);

void STARTBUILD(Queue *Q);

void FINISHBUILD(Queue *Q, Stack *S, Stack *QS);

void ADDCOMPONENT(Stack *BuildKomponen, TabInv *Inventory);

void REMOVECOMPONENT(Stack *BuildKomponen, TabInv *Inventory);

void SHOP(TabInv *Toko, TabInv *Inventory, int *duitPemain);

void DELIVER();

void END_DAY();

void SAVE();

void MAP();

int EXIT(char *opsiKeluar);


#endif