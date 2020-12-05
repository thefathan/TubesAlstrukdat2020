#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M) {
// ! NB dan NK didapat dari Configure */
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK dengan
   elemen yang tidak terdefinisi */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxBrs + 1 dan MaxKol + 1 */

  /* KAMUS LOKAL */
    int i, j;

    /* ALGORITMA */
    Mem(*M) = (int **) malloc ((NB + 1) * sizeof(int *));

    for (i = 0; i <= NB; i++) {
      (*M).Mem[i] = (int *) malloc ((NK + 1) * sizeof(int *));
    }

    MaxBrs(*M) = NB;
    MaxKol(*M) = NK;

    for (i = 1; i <= NB; i++) {
      for (j = 1; j <= NK; j++) {
        Isi(*M, i, j) = ValUndef;
      }
    }
}

void DealokasiMatriks (MATRIKS * M) {
/* I.S. M terdefinisi; */
/* F.S. Mem(M) dikembalikan ke system, MaxBrs(M)=0; MaxKol(M)=0 */

  /* KAMUS LOKAL */

  /* ALGORITMA */
    free(Mem(*M));
    MaxBrs(*M) = 0;
    MaxKol(*M) = 0;
}

/* ********** KELOMPOK BACA/TULIS ********** */

void TulisMATRIKS (MATRIKS M) {
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

    /* KAMUS LOKAL */
    int i, j;

    /* ALGORITMA */
    for (i = 1; i <= MaxBrs(M); i++) {
      for (j = 1; j < MaxKol(M); j++) {
        printf("%d ", Isi(M, i, j));
      }
      printf("%d\n", Isi(M, i, j));
    }
}

/* ********** Operasi lain ********** */
int NBElmtMatriks (MATRIKS M) {
// ? Untuk debugging doang
/* Mengirimkan banyaknya elemen M */

    /* KAMUS LOKAL */
    int total;
    int i, j;

    /* ALGORITMA */
    total = 0;

    for (i = 1; i <= MaxBrs(M); i++) {
      for (j = 1; j <= MaxKol(M); j++) {
        if (Isi(M, i, j) != 0) {
          total += 1;
        }
      }
    }
    return total;
}

