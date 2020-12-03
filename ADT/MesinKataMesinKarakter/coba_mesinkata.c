#include <stdio.h>
#include "mesinkata.c"

int main(){
    STARTKATA();
    while(CKata.Length > 0 && !IsEOP()){
        printf("%s\n", CKata.TabKata);
        ADVKATA();
    }
    return 0;
}
