#include <stdio.h>
#include "boolean.h"
#include <string.h>
#include "list.c"


#define MAXCHAR 100000

int main () {
    FILE *fp;
    char x;
    char array[115][2000];
    char array2[115][2000];
    char str[MAXCHAR];
    char* filename = "anu.txt";
    int i = 0, j = 0;
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, sizeof(str), fp) != NULL) { 
        strcpy(array[i],str);
        i++;
    }
    fclose(fp);

    TabInv L;
    L = MakeList();
    int harga, tipe, jumlah;
    char namakomponen[100], dtm[150], trasit[115];

    for (int a = 0; a < i; a++) {
        
        strcpy(dtm, array[a]);
        sscanf(dtm, "%s %d %d  %d", namakomponen, &harga, &tipe, &jumlah);
        NamaKomponen NK = {"dummy", harga, tipe, jumlah};
        strcpy(NK.Nama, namakomponen);
        InsertLast(&L, NK);
    }
    PrintListShop(L);
    return 0;
}



    // TabInv L; int i;
    



    // L = MakeList();
    // for (i=0; i<11; i++) {
    //     NamaKomponen NK = {"AMD Ryzen 13 1000GB", 10000, i, 1};
    //     InsertLast(&L, NK);
    // }

    // printf("%d\n", Length(L));
    // printf("%d\n", GetCapacity(L));
    // // printf("%s,%d\n", Get(L,1).Nama, Get(L,1).kodeJenis);
    // PrintList(L);
    // PrintListStatus(L);
    // NamaKomponen el = {"AMD Ryzen 13 1000GB", 10000, 9, 1};
    // printf("%d\n", Search1(L, el));
    // DeleteAt(&L, el);
    // PrintList(L);
    // PrintListInventory(L);
    // PrintListShop(L);

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