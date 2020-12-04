#include <stdio.h>
#include "mesinkata.c"

int main(){
    int hitung_newline = 0;
    int absis, ordinat;

    START();
    while(!IsEOP() && hitung_newline < 6){ //kalo mau nyari customer ke-n, letaknya di baris ke-n+4
        int hitung_spasi;

        if (CC == '\n'){ //tiap ada newline, jumlah spasi diitung ulang
            hitung_newline++;
            hitung_spasi = 0;
        }
        if (CC == BLANK){
            hitung_spasi++;
        }
        if (hitung_spasi == 1){ //absis = satu kali spasi setelah C
            absis = GetCC() - '0';
        }
        else if(hitung_spasi == 2){ //ordinat = dua kali spasi abis C
            ordinat = GetCC() - '0';
        }

        ADV();
    }


    printf("%i %i", absis, ordinat);
    return 0;
}
