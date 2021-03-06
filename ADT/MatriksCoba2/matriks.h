

/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */



#ifndef MATRIKS_H
#define MATRIKS_H

#include <stdio.h>
#include "boolean.h"
#include "../Point/point.c"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define KolMin 1

#define ValUndef 0
/* Nilai elemen tak terdefinisi */

typedef int indeks; /* indeks baris, kolom */
typedef char Cell;
typedef struct {
    Cell **Mem; /* memori tempat penyimpan elemen (container) */
    int MaxBrs; /* ukuran elemen baris */
    int MaxKol; /* ukuran elemen kolom */
} MATRIKS;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M);
// ! NB dan NK didapat dari Configure */
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK dengan
   elemen yang tidak terdefinisi */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxBrs + 1 dan MaxKol + 1 */

void DealokasiMatriks (MATRIKS * M);
/* I.S. M terdefinisi; */
/* F.S. Mem(M) dikembalikan ke system, MaxBrs(M)=0; MaxKol(M)=0 */

/* *** Selektor *** */
#define MaxBrs(M)   (M).MaxBrs
#define MaxKol(M)   (M).MaxKol
#define Mem(M)      (M).Mem
#define Isi(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisMATRIKS (MATRIKS M);
// ? Untuk debugging doang kayaknya
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** Operasi lain ********** */
int NBElmtMatriks (MATRIKS M);
// ? Untuk debugging doang
/* Mengirimkan banyaknya elemen M */

#endif
