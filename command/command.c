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

// POINT pemain, customer_ke //Menampung koordinat terbaru dari pemain dan koordinat customer yang akan dituju

void MOVE() {
    printf("========================================================\n");
    printf("Command MOVE belum diimplementasikan.\n");
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void STATUS(TabInv *Inventory, int *duitPemain) {
    printf("========================================================\n");
    printf("Uang tersisa: $%d\n", *duitPemain);
    printf("Build yang sedang dikerjakan: pesanan <23> untuk pelanggan <4>.\n");
    printf("Lokasi: pemain sedang berada pada <base>.\n");
    printf("Inventory Anda: \n");
    PrintListInventory(*Inventory);
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void CHECKORDER() {
    printf("========================================================\n");
    printf("Command CHECKORDER belum diimplementasikan.\n");
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void STARTBUILD( /* Queue Q, Stack *S*/ ) {
    printf("========================================================\n");
    // printf ("kamu telah memulai pesanan %d untuk pelanggan %d \n",order_id(Head(*Q)), pemesanan(Head(*Q)))
    // CreateEmptyStack();
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void FINISHBUILD( /* Queue *Q, Stack *S*/ ) {
    printf("========================================================\n");
    // int count = 0;

    // for (int i=0, i<8, i++){
    //     if (S.T[i] == (Head(*Q))->T[i]){
    //         count = count+1;
    //     }
    // }

    // if (count == 8) {
    //     printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d\n", order_id(Head(*Q)), pemesanan(Head(*Q)));
    //     for (int i=0, i<8, i++) {
    //         Pop(S, isiStack); // membersihkan isi stack
    //     }
    // }
    // else {
    //     printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan\n")
    // }
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
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
        DeleteAt(Inventory, komponenDipilih);
    }
    else {
        printf("Komponen sudah penuh!\n");
    }

    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void REMOVECOMPONENT(Stack *BuildKomponen, TabInv *Inventory) {
    if (!(IsStackEmpty(*BuildKomponen))) {
        printf("========================================================\n");
        Pop(BuildKomponen, &isiStack);
        printf("Komponen %s berhasil dicopot!\n", isiStack.Nama);
        InsertLast(Inventory, isiStack);
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
    printf("========================================================\n");
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

void DELIVER(/*POINT player, POINT customer*/) {
    printf("========================================================\n");
    // if(EQ(player, customer)){
    //   printf("Pesanan ke %d berhasil diantarkan kepada pelanggan %d\n", order_id(Head(*Q)), pemesanan(Head(*Q))); }
    // printf("Pemain sedang tidak berada di lokasi customer);

    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void END_DAY() {
    printf("========================================================\n");
    printf("Command END_DAY belum diimplementasikan.\n");
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void SAVE() {
    printf("========================================================\n");
    printf("Command SAVE belum diimplementasikan.\n");
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void MAP() {
    printf("========================================================\n");
    printf("Command MAP belum diimplementasikan.\n");
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

int EXIT(char *opsiKeluar) {
    if (strcmp(opsiKeluar, "YA") == 0) {
        return 1;
    }
    return 0;
}
