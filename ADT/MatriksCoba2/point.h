#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void MakePOINT (POINT * P, int X, int Y);
/* Membentuk sebuah POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* I.S. P sembarang   */
/* F.S. P terdefinisi */

/* TULIS dengan Output Device */
void TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* Me-copy data-data Point */
POINT CopyPOINT(POINT P);

#endif
