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

void ADDCOMPONENT(Stack *BuildKomponen, TabInv *Inventory) {

    printf("========================================================\n");
    printf("Komponen yang telah terpasang: \n");
    PrintStackAddComponent(BuildKomponen);
    printf("Komponen yang tersedia: \n");
    PrintListInventory(*Inventory);
    printf("Komponen yang ingin dipasang: ");

    int opt;
    scanf("%d", &opt);
    while (opt < 1 | opt > Length(*Inventory)) {
        printf("Tolong masukkan angka yang benar!\n");
        sleep(1);
        printf("Komponen yang ingin dipasang: ");
        scanf("%d", &opt);
    }

    Sinfotype komponenDipilih = Get(*Inventory, opt-1);
    if (!(IsStackFull(*BuildKomponen))) {
        Push(BuildKomponen, komponenDipilih);
        printf("Komponen berhasil dipasang!\n");
    }
    else {
        printf("Komponen sudah penuh!\n");
    }

    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void REMOVECOMPONENT(Stack *BuildKomponen) {
    if (!(IsStackEmpty(*BuildKomponen))) {
        Pop(BuildKomponen, &isiStack);
        printf("Komponen %s berhasil dicopot!\n", isiStack.Nama);
        printf("========================================================\n");
    }
    else {
        printf("Seluruh komponen sudah dilepas.\n");
        printf("========================================================\n");
    }
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void SHOP(TabInv *Toko, TabInv *Inventory, int *duitPemain) {
    int optbeli, jumlahbeli, hargatotal;

    printf("Sisa uang Pak Santo: %d\n", *duitPemain);
    printf("Komponen yang tersedia: \n");
    PrintListShop(*Toko);
    printf("Komponen yang ingin dibeli: ");
    scanf("%d", &optbeli);

    NamaKomponen komponenDibeli = Get(*Toko, optbeli-1);
    printf("Masukkan jumlah yang ingin dibeli: ");

    scanf("%d", &jumlahbeli);

    hargatotal = jumlahbeli*Get(*Toko, optbeli-1).harga;
    if (hargatotal <= *duitPemain) {
        printf("Komponen berhasil dibeli!\n");
        for (int i=0; i < jumlahbeli; i++) {
            InsertLast(Inventory, komponenDibeli);
        }
        *duitPemain = *duitPemain - hargatotal;
    }
    else {
        printf("Uang tidak cukup!\n");
    }
    PrintList(*Inventory);
    printf("Sisa uang Pak Santo: %d\n", *duitPemain);
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
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