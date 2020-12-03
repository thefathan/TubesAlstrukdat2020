#include "mesinkata.h"
#include "mesinkarakter.c"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
   while ((CC == BLANK) && !IsEOP())
   {
       ADV();
   }
}

void STARTKATA(){
    START();
    ADVKATA();
}

void ADVKATA(){
    IgnoreBlank();
    SalinKata();
}

void SalinKata(){
    CKata.Length = 0;
    do {

        CKata.TabKata[CKata.Length] = CC;
        CKata.Length++;
        CKata.TabKata[CKata.Length] = 0;
        ADV();

    }while ( !IsEOP() && (CC != BLANK) && (CKata.Length < NMax));

}
