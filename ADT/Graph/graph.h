#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"

#ifndef GRAPH_H
#define GRAPH_H
#define NILL NULL

/* Definisi Tipe Data */
typedef struct tNodeGraph* adrNode;
typedef struct tSuccNode* adrSuccNode;
typedef struct tNodeGraph {
	int Id;
	int NPred;
	adrNode Succ;
	adrSuccNode Trail;
	adrNode Next;
} NodeGraph;

typedef struct tSuccNode {
	adrNode Succ;
	adrSuccNode Trail;
	adrSuccNode Next;
} SuccNodeGraph;

typedef struct {
	adrNode First;
} Graph;

/* *** Selektor *** */
/* Jika G: Graph, Pn: adrNode, Pt: adrSuccNode, maka: */
#define First(G) (G).First
#define Id(Pn) (Pn)->Id
#define NPred(Pn) (Pn)->NPred
#define Trail(Pn) (Pn)->Trail
#define Next(Pn) (Pn)->Next
#define Succ(Pt) (Pt)->Succ

/* *** Konstruktor *** */
void CreateGraph (int X, Graph* G);
/* I.S. Sembarang; F.S. Terbentuk Graph dengan satu simpul dengan Id=X */

/* *** Manajemen Memory List Simpul (Leader) *** */

adrNode AlokNode (int X);
/* Mengembalikan address hasil alokasi Simpul X. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=Nil,
dan Next(P)=Nil. Jika alokasi gagal, mengembalikan Nil. */

void DealokNode (adrNode P);
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */

/* *** Manajemen Memory List Successor (Trailer) *** */

adrSuccNode AlokSuccNode (adrNode Pn);
/* Mengembalikan address hasil alokasi. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan Pt, maka Succ(Pt)=Pn dan Next(Pt)=Nil. Jika
alokasi gagal, mengembalikan Nil. */

void DealokSuccNode (adrSuccNode P);
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */

/* *** Fungsi/Prosedur Lain *** */

adrNode SearchNode (Graph G, int X);
/* mengembalikan address simpul dengan Id=X jika sudah ada pada graph G,
Nil jika belum */

adrSuccNode SearchEdge (Graph G, int prec, int succ);
/* mengembalikan address trailer yang menyimpan info busur (prec,succ)
jika sudah ada pada graph G, Nil jika belum */

void InsertNode (Graph* G, int X, adrNode* Pn);
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil. */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G. */
/* F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi
address simpul X. Jika alokasi gagal, G tetap, Pn berisi Nil */

void InsertEdge (Graph* G, int prec, int succ);
/* Menambahkan busur dari prec menuju succ ke dalam G */
/* I.S. G, prec, succ terdefinisi. */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur
(prec,succ) ke G. Jika simpul prec/succ belum ada pada G,
tambahkan simpul tersebut dahulu. Jika sudah ada busur (prec,succ)
di G, maka G tetap. */

boolean isEqual (adrNode P, int X);
/* Memeriksa apakah Id adress P sama dengan X */

#endif
