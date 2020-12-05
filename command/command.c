#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "string.h"


// Stack BuildKomponen; // Stack yang ada pada saat merakit komponen komputer
Sinfotype isiStack;  // Isi dari stack BuildKomponen
// TabInv Inventory, Toko; // List Inventory merupakan sebuah kumpulan komponen komputer, digunakan di Shop/Toko
// int duitPemain;

// POINT pemain, customer_ke //Menampung koordinat terbaru dari pemain dan koordinat customer yang akan dituju

void MOVE() {               // Baru template, belum diimplementasikan
    int nomortujuan;
    printf("========================================================\n");
    printf("Command MOVE belum diimplementasikan.\n");
    printf("Kamu berada pada <base>.\n");
    printf("Daftar lokasi yang dapat dicapai:\n");
    printf("<1. Pelanggan 2>\n");
    printf("<2. Pelanggan 5>\n");
    printf("Nomor tujuan: ");
    scanf("%d", &nomortujuan);
    printf("Kamu telah mencapai lokasi <Pelanggan 5>!\n");
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void STATUS(TabInv *Inventory, Queue *Q, int *duitPemain) {
    printf("========================================================\n");
    printf("Uang tersisa: $%d\n", *duitPemain);
    if (FrontQueue(*Q).order_id < 1) {
        printf("Build yang sedang dikerjakan: Belum ada pesanan yang dimulai.\n");
    }
    else {
        printf("Build yang sedang dikerjakan: Pesanan %d untuk pelanggan %d.\n", FrontQueue(*Q).order_id, FrontQueue(*Q).pemesanan);
    }
    printf("Lokasi: pemain sedang berada pada <base>.\n");
    printf("Inventory Anda: \n");
    PrintListStatus(*Inventory);
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void CHECKORDER(Queue *Q, Stack *QS) {
    printf("========================================================\n");
    if (FrontQueue(*Q).order_id < 1) {
        printf("Belum ada orderan yang dimulai pengerjaannya. Silakan lakukan STARTBUILD untuk memulai pengerjaan.\n");
    }
    else {
        printf("Nomor Order: %d\n", FrontQueue(*Q).order_id);
        printf("Pemesan: Pelanggan %d\n", FrontQueue(*Q).pemesanan);
        printf("Invoice: $%d\n", FrontQueue(*Q).invoice);
        printf("Komponen:\n");
        PrintStackAddComponent(QS);
    }
    // printf("1. <Motherboard B450>\n");
    // printf("2. <Ryzen 5 4500>\n");
    // printf("3. <Kingston 16GB>\n");
    // printf("4. <Cooler Master Silent Cooler>\n");
    // printf("5. <NZXT H510i>\n");
    // printf("6. <AMD Radeon 6800XT>\n");
    // printf("7. <HDD 1TB>\n");
    // printf("8. <PSU 600W>\n");
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void STARTBUILD(Queue *Q) {
    printf("========================================================\n");
    if (FrontQueue(*Q).order_id < 1) {
        ElTypeQueue awalan = Dequeue(Q);
        printf ("Kamu telah memulai pesanan %d untuk pelanggan %d.\n", FrontQueue(*Q).order_id, FrontQueue(*Q).pemesanan);
    } else {
        printf ("Kamu telah memulai pesanan %d untuk pelanggan %d.\n", FrontQueue(*Q).order_id, FrontQueue(*Q).pemesanan);
    }
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void FINISHBUILD(Queue *Q, Stack *S, Stack *QS, int *nomorantrian, int *duitPemain) {
    printf("========================================================\n");
    Stack C1 = *S;
    Stack C2 = *QS;
    if (IsStackSama(&C1, &C2) && (S->TOP == 8)) {
        printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d.\n", FrontQueue(*Q).pemesanan, FrontQueue(*Q).pemesanan);
        *duitPemain = *duitPemain + FrontQueue(*Q).invoice;
        Sinfotype buangan;
        for (int i = 0; i < S->TOP; i++) {
            Pop(S, &buangan);
        }
        ElTypeQueue selesai = Dequeue(Q);
        *nomorantrian++;
    }
    else {
        printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
    }

    // COBA



    // int count = 0;

    // for (int i=0, i<8, i++){
    //     if (strcmp(S.T[i], (Head(*Q))->T[i]) == 0){
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
    if (!IsListEmpty(*Inventory)) {
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
    }
    else {
        printf("Anda tidak punya apa-apa di inventory anda. Silahkan pergi ke SHOP untuk membeli sesuatu.\n");
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
    printf("\nSisa uang Pak Santo: %d\n", *duitPemain);
    printf("========================================================\n");
    printf("\nTekan enter untuk kembali ke menu command.\n");
    getchar();
}

void DELIVER(/* POINT player, POINT customer, Queue *Q */) {
    printf("========================================================\n");
    // if(EQ(player, customer)){
    //   printf("Pesanan ke %d berhasil diantarkan kepada pelanggan %d\n", order_id(Head(*Q)), pemesanan(Head(*Q))); }
    // printf("Pemain sedang tidak berada di lokasi customer);
    printf("Pesanan <#23> berhasil diantarkan kepada pelanggan <3>!\n");
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

    for(int i = 0; i <= NK + 1; i++){
            printf("*");
        }
        for(int j = 1; j <= NB; j++){
            for(int i = 1; i <= NK; i++){
                printf("*");
                POINT B = MakePOINT(i, j);
                if(EQ(P, B)){
                    printf(Isi(map, j, i));
                }
                else{
                    printf(" ");
                }
            }
        }
        for(int i = 0; i <= NK + 1; i++){
            printf("*");
        }

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
