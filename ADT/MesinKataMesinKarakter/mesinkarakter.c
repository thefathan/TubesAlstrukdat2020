#include "mesinkarakter.h"
#include <stdio.h>

char CC;        /* bisa diakses dimana saja */
boolean EOP;    /* bisa diakses dimana saja */

static FILE * pita;
static int retval;

void START() {
	/* Algoritma */
	pita = fopen("hai.txt","r");
	ADV();
}

void ADV() {
	fscanf(pita,"%c",&CC);
	EOP = (CC == MARK);
	if (EOP) {
       fclose(pita);
 	}
}

char GetCC(){
    return CC;
}

boolean IsEOP(){
    return (CC == MARK);
}
