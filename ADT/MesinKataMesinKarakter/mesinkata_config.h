/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "mesinkar_config.c"
// #include "../matriks/matriks.h"
// #include "../graph/graph.h"
#include "string.h"

#define NMax 500
#define BLANK1 ' '
#define BLANK2 '\n'

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
	int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK1 atau CC ≠ BLANK2 */
void IgnoreBlank();

/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
void STARTKATA(char * C);

/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
void ADVKATA();

/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void SalinKata();

/* I.S. Kata K terdefinisi */
/* F.S. K tercetak di layar tanpa karakter tambahan di awal maupun di akhir */
void PrintKata (Kata K);

/* Kata K berisi integer dalam bentuk kata, mengkonversinya ke int */
int KataToInt (Kata K);

/* K.Length = 1 , mengeluarkan konversi K ke char */
char KataToChar (Kata K);

/* I.S. K1 terdefinsi, K2 sembarang */
/* F.S. K2 merupakan copyan dari K1, berisi sama dengan K1 */
void CopyKata(Kata K1,Kata *K2);



#endif
