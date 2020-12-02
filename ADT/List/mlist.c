#include <stdio.h>
#include "boolean.h"
#include <string.h>
#include "list.c"


int main() {
    TabInv L; int i;
    
    L = MakeList();
    for (i=0; i<11; i++) {
        NamaKomponen NK = {"AMD Ryzen 13 1000GB", 10000, i};
        InsertLast(&L, NK);
    }

    printf("%d\n", Length(L));
    printf("%d\n", GetCapacity(L));
    // printf("%s,%d\n", Get(L,1).Nama, Get(L,1).kodeJenis);
    PrintList(L);
    NamaKomponen el = {"AMD Ryzen 13 1000GB", 10000, 9};
    printf("%d\n", Search1(L, el));
    DeleteAt(&L, el);
    PrintList(L);
    // PrintListInventory(L);
    // PrintListShop(L);
}

/* OUTPUT

1. AMD Ryzen 13 1000GB, 6
2. AMD Ryzen 13 1000GB, 6
3. AMD Ryzen 13 1000GB, 6
4. AMD Ryzen 13 1000GB, 6
5. AMD Ryzen 13 1000GB, 6
6. AMD Ryzen 13 1000GB, 6
7. AMD Ryzen 13 1000GB, 6
8. AMD Ryzen 13 1000GB, 6
9. AMD Ryzen 13 1000GB, 6
10. AMD Ryzen 13 1000GB, 6
11. AMD Ryzen 13 1000GB, 6
12. AMD Ryzen 13 1000GB, 6
*/