#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "string.h"


// Stack BuildKomponen; // Stack yang ada pada saat merakit komponen komputer
Sinfotype isiStack;  // Isi dari stack BuildKomponen
// NamaKomponen isiInventory; // Isi dari List Inventory (Tipenya sama kayak Sinfotype)
// TabInv Inventory, Toko; // List Inventory merupakan sebuah kumpulan komponen komputer, digunakan di Shop/Toko
// int duitPemain;

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

void ADDCOMPONENT(Stack BuildKomponen, TabInv Inventory) {

    printf("Komponen yang telah terpasang: \n");
    PrintStackAddComponent(&BuildKomponen);
    printf("Komponen yang tersedia: \n");
    PrintListInventory(Inventory);
    printf("Komponen yang ingin dipasang: ");
    int opt;
    scanf("%d", &opt);
    printf("setelah scan\n");
    Sinfotype komponenDipilih = Get(Inventory, opt-1);
    Push(&BuildKomponen, komponenDipilih);
    PrintStack(&BuildKomponen);
    getchar();
}

void REMOVECOMPONENT(Stack BuildKomponen) {
    Pop(&BuildKomponen, &isiStack);
    printf("Komponen %s berhasil dicopot!\n", isiStack.Nama);
    PrintStack(&BuildKomponen);
    getchar();
    printf("done");
}

void SHOP(TabInv Toko, TabInv Inventory, int duitPemain) {
    int optbeli, jumlahbeli, hargatotal;

    printf("Komponen yang tersedia: \n");
    PrintListShop(Toko);
    printf("Komponen yang ingin dibeli: ");
    scanf("%d", &optbeli);

    NamaKomponen komponenDibeli = Get(Toko, optbeli-1);
    printf("Masukkan jumlah yang ingin dibeli: ");

    scanf("%d", &jumlahbeli);

    hargatotal = jumlahbeli*Get(Toko, optbeli-1).harga;
    if (hargatotal <= duitPemain) {
        printf("Komponen berhasil dibeli!\n");
        for (int i=0; i < jumlahbeli; i++) {
            InsertLast(&Inventory, komponenDibeli);
        }
        duitPemain = duitPemain - hargatotal;
    }
    else {
        printf("Uang tidak cukup!\n");
    }
    PrintList(Inventory);
    printf("%d", duitPemain);
    getchar();
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