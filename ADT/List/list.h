#ifndef __DYNAMIC_LIST__
#define __DYNAMIC_LIST__
#include "boolean.h"

#define IdxUndef -999
#define IdxMax 9999
#define InitialSizeList 10

typedef char Komponen[255];
typedef struct {
    Komponen Nama;
    int harga;
    int kodeJenis;
} NamaKomponen;


typedef struct {
    NamaKomponen *TI;
    int Capacity;
    int Neff;
} TabInv;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk List kosong dengan ukuran InitialSize
 */
TabInv MakeList();

/**
 * Destruktor
 * I.S. List terdefinisi
 * F.S. list->A terdealokasi
 */
void DeallocateList(TabInv *list);

/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
boolean IsListEmpty(TabInv list);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
int Length(TabInv list);

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
NamaKomponen Get(TabInv list, int i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
int GetCapacity(TabInv list);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
void InsertAt(TabInv *list, NamaKomponen el, int i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
void InsertLast(TabInv *list, NamaKomponen el);

/**
 * Fungsi untuk menambahkan elemen baru di awal list.
 * Prekondisi: list terdefinisi
 */
void InsertFirst(TabInv *list, NamaKomponen el);

void DeleteAt(TabInv *list, NamaKomponen el);

int Search1(TabInv list, NamaKomponen el);

boolean SearchB(TabInv list, NamaKomponen el);

void PrintList(TabInv list);

void PrintListInventory(TabInv list);

void PrintListShop(TabInv list);

#endif