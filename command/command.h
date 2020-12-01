#ifndef command_H
#define command_H


#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/List/list.c"
#include "../ADT/MesinKataMesinKarakter/mesinkarakter.c"
#include "../ADT/MesinKataMesinKarakter/mesinkata.c"
#include "../ADT/Point/point.c"
#include "../ADT/Queue/circular_queue.c"
#include "../ADT/Stack/stack.c"


// Belum ada parameter prosedur di command.
// Silakan dilanjut disini

void MOVE();

void STATUS();

void CHECKORDER();

void STARTBUILD();

void FINISHBUILD();

void ADDCOMPONENT();

void REMOVECOMPONENT();

void SHOP();

void DELIVER();

void END_DAY();

void SAVE();

void MAP();

void EXIT();


#endif