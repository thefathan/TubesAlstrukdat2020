#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "string.h"


Stack BuildKomponen; // Stack yang ada pada saat merakit komponen komputer
Sinfotype isiStack;  // Isi dari stack BuildKomponen
NamaKomponen isiInventory; // Isi dari List Inventory (Tipenya sama kayak Sinfotype)
TabInv Inventory, Toko; // List Inventory merupakan sebuah kumpulan komponen komputer, digunakan di Shop/Toko
int duitPemain;

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

void ADDCOMPONENT() {
    int opt;

    printf("Komponen yang telah terpasang: \n");
    PrintStack(&BuildKomponen);
    printf("Komponen yang tersedia: \n");
    PrintList(Inventory);
    printf("Komponen yang ingin dipasang: ");
    scanf("%d", opt);
    Sinfotype komponenDipilih = Get(Inventory, opt-1);
    Push(&BuildKomponen, komponenDipilih);
    getchar();
}

void REMOVECOMPONENT() {
    Pop(&BuildKomponen, &isiStack);
    printf("Komponen %s berhasil dicopot!\n", isiStack.Nama);
    getchar();
}

void SHOP() {
    int optbeli, jumlahbeli, hargatotal;

    printf("Komponen yang tersedia: \n");
    PrintListShop(Toko);
    printf("Komponen yang ingin dibeli: ");
    scanf("%d", optbeli);
    NamaKomponen komponenDibeli = Get(Toko, optbeli-1);
    printf("Masukkan jumlah yang ingin dibeli: ");
    scanf("%d", jumlahbeli);

    hargatotal = jumlahbeli*Get(Toko, optbeli-1).harga;
    if (hargatotal <= duitPemain) {
        printf("Komponen berhasil dibeli!\n");
        InsertLast(&Inventory, komponenDibeli);
        duitPemain - hargatotal;
    }
    else {
        printf("Uang tidak cukup!\n");
    }
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