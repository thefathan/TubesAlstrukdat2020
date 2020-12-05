#ifndef command_H
#define command_H


#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/List/list.c"
#include "../ADT/Stack/stack.c"
#include "../ADT/Queue/circular_queue.c"
#include "../ADT/Alamat/alamat.c"
#include "../ADT/Graph/graph.c"
#include "../ADT/array/array.c"
// #include "../ADT/MatriksCoba2/matriks.c"
#include "../ADT/MesinKataMesinKarakter/mesinkata_config.c"

// Belum ada parameter prosedur di command.
// Silakan dilanjut disini





void MOVE();

void STATUS(TabInv *Inventory, Queue *Q, int *duitPemain);

void CHECKORDER(Queue *Q, Stack *QS);

void STARTBUILD(Queue *Q);

void FINISHBUILD(Queue *Q, Stack *S, Stack *QS, int *nomorantrian,int *duitPemain);

void ADDCOMPONENT(Stack *BuildKomponen, TabInv *Inventory);

void REMOVECOMPONENT(Stack *BuildKomponen, TabInv *Inventory);

void SHOP(TabInv *Toko, TabInv *Inventory, int *duitPemain);

void DELIVER();

void END_DAY();

void SAVE();

void MAP( /*int NB, int NK, POINT P, MATRIKS map */ );

int EXIT(char *opsiKeluar);


#endif
