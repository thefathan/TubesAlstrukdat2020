#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "../ADT/List/list.h"




#define MAXCHAR 100000




// typedef char Komponen[255];
// typedef struct {
//     Komponen Nama;
// } NamaKomponen;


// typedef struct {
//     NamaKomponen *TI;
//     int Capacity;
//     int Neff;
// } TabInv;


int main () {
    FILE *fp;
    char x;
    char array[4][2000];
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
    for (int d = 0; d < i; d++){
        printf("%s", array[d]);
    }
    fclose(fp);

   
   
    int harga, tipe, jumlah;
    char namakomponen[100], dtm[150];

    strcpy( dtm, "AMDBakso1000GB 10000 1 12" );
    sscanf( dtm, "%s %d %d  %d", namakomponen, &harga, &tipe, &jumlah );

    printf("\nnama = %s ; tipe = %d ; harga = %d  jumlahnya = %d\n", namakomponen, tipe, harga, jumlah);

    return(0);
}