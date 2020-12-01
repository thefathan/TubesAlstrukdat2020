#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "string.h"


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

void ADDCOMPONENT(Stack *BuildKomponen, Sinfotype Inventory) {
    Push(&BuildKomponen, Inventory);
}

void REMOVECOMPONENT(Stack *BuildKomponen, Sinfotype *Inventory) {
    Pop(&BuildKomponen, &Inventory);
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