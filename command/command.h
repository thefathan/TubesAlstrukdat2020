#ifndef command_H
#define command_H


#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/List/list.h"
#include "../ADT/MesinKataMesinKarakter/mesinkarakter.h"
#include "../ADT/MesinKataMesinKarakter/mesinkata.h"
#include "../ADT/Point/point.h"
#include "../ADT/Queue/circular_queue.h"
#include "../ADT/Stack/stack.h"


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