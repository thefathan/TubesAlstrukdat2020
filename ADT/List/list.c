#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk List kosong dengan ukuran InitialSize
 */
TabInv MakeList() {
    TabInv list;
    list.TI  = (NamaKomponen *) malloc(InitialSizeList * sizeof(NamaKomponen));
    list.Capacity = InitialSizeList;
    list.Neff = 0;
    return list;
}

void DeallocateList(TabInv *list) {
    free(list->TI);
}

/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
boolean IsListEmpty(TabInv list) {
    return list.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
int Length(TabInv list) {
    return list.Neff;
}

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
NamaKomponen Get(TabInv list, int i) {
    return list.TI[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
int GetCapacity(TabInv list) {
    return list.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
void InsertAt(TabInv *list, NamaKomponen el, int i) {
    int length = Length(*list);
    int capacity = GetCapacity(*list);

    if (length >= capacity) {
        int desiredCapacity = 2*capacity;
        NamaKomponen *array = (NamaKomponen *) malloc(desiredCapacity * sizeof(NamaKomponen));
        for (int a = 0; a < length; a++) {
            array[a] = list->TI[a];
        }
        free(list->TI);

        list->TI = array;
        list->Capacity = desiredCapacity;
    }

    for (int a = length - 1; a >= i; a--) {
        list->TI[a + 1] = list->TI[a];
    }

    list->TI[i] = el;
    list->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
void InsertLast(TabInv *list, NamaKomponen el) {
    int insertAt = Length(*list);
    InsertAt(list, el, insertAt);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal list.
 * Prekondisi: list terdefinisi
 */
void InsertFirst(TabInv *list, NamaKomponen el) {
    InsertAt(list, el, 0);
}


void DeleteAt(TabInv *list, NamaKomponen el) {
    if (SearchB(*list, el)) {
        int lokasi = Search1(*list, el);
        if (lokasi != Length(*list)-1) {
            for (int x = lokasi; x <= Length(*list)-1; x++) {
                list->TI[x] = list->TI[x+1];
            }
            list->Neff--;
        }
        else {
            list->Neff--;
            NamaKomponen *array = (NamaKomponen *) malloc(list->Capacity * sizeof(NamaKomponen));
            for (int y = 0; y < Length(*list); y++) {
                array[y] = Get(*list, y);
            }
            DeallocateList(list);
            list->TI = array;
        }
    }
    else {
        int lokasi = Search1(*list, el);
    }
}


int Search1(TabInv list, NamaKomponen el) {
    for (int i = 0; i < Length(list); i++) {

        NamaKomponen ketemu = Get(list, i);
        boolean strsama = (strcmp(ketemu.Nama, el.Nama) == 0);
        if (strsama && (ketemu.kodeJenis == el.kodeJenis) && (ketemu.harga == el.harga)) {
            return i;
        }
    }
    return IdxUndef;
}

boolean Search2(TabInv list, NamaKomponen el) {
    boolean Found = false;
    int i = 0;
    while ((!Found) && (i < Length(list))) {

        NamaKomponen ketemu = Get(list, i);
        boolean strsama = (strcmp(ketemu.Nama, el.Nama) == 0);
        if (strsama && (ketemu.kodeJenis == el.kodeJenis) && (ketemu.harga == el.harga)) {
            Found = true;
        }
        else {
            i++;
        }
    }
    return Found;
}


void PrintList(TabInv list) {
    int i = 0;
    while (i < list.Neff) {
        printf("%d. %s, %d, %d, %d\n", i+1, Get(list,i).Nama, Get(list,i).harga, Get(list,i).kodeJenis, Get(list,i).jumlah);
        i++;
    }
}

void PrintListInventory(TabInv list) {
    int i = 0;
    while (i < list.Neff) {
        printf("%d. %s\n", i+1, Get(list,i).Nama);
        i++;
    }
}

void PrintListShop(TabInv list) {
    int i = 0;
    while (i < list.Neff) {
        printf("%d. %s - $%d\n", i+1, Get(list,i).Nama, Get(list,i).harga);
        i++;
    }
}

void PrintListStatus(TabInv list) {
    int i = 0;
    while (i < list.Neff) {
        printf("%d. %s  (%d)\n", i+1, Get(list,i).Nama, Get(list,i).jumlah);
        i++;
    }
}
