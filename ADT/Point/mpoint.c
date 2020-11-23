#include <stdio.h>
#include "point.c"


int main() {
    float x,y;
    POINT P1, P2;


    printf("// Prosedur BacaPOINT // Masukkan sebuah absis dan ordinat (Untuk P1)\n");
    BacaPOINT(&P1);
    printf("// Prosedur TulisPOINT // Koordinat yang dibentuk dari apa yang anda tulis adalah(dalam bentuk desimal 2 angka dibelakang koma, Untuk P1):\n");
    TulisPOINT(P1);
    printf("\n");

    printf("// Prosedur BacaPOINT // Masukkan sebuah absis dan ordinat (Untuk P2)\n");
    BacaPOINT(&P2);
    printf("// Prosedur TulisPOINT // Koordinat yang dibentuk dari apa yang anda tulis adalah(dalam bentuk desimal 2 angka dibelakang komaUntuk P2):\n");
    TulisPOINT(P2);
    printf("\n");

    printf("// Fungsi EQ dan NEQ // Apakah P1 dan P2 sama?\n");
    if (EQ(P1,P2)) {
        printf("P1 dan P2 bernilai sama yaitu X = %.f dan Y = %.f\n", Absis(P1), Ordinat(P2));
    }
    else if(NEQ(P1,P2)) {
        printf("P1 dan P2 bernilai beda yaitu,\n");
        printf("Untuk P1(%.f,%.f) dan P2(%.f,%.f)\n", Absis(P1), Ordinat(P1), Absis(P2), Ordinat(P2));
    }
}



