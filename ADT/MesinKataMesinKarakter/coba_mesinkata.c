#include <stdio.h>
#include "mesinkata.c"

int main(){
    STARTKATA();
    while(CKata.Length > 0 && CC != MARK){
        printf("%s\n", CKata.TabKata);
        ADVKATA();
    }
    return 0;
}
