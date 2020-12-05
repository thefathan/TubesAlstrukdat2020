#include <stdio.h>
#include <stdlib.h>
#include "../graph/graph.h"

void CreateGraph (int X, Graph* G){
/* I.S. Sembarang; F.S. Terbentuk Graph dengan satu simpul dengan Id=X */
	/*G = (adrNode) malloc (sizeof(NodeGraph)); */
	First(*G) = NILL;
	adrNode P;
	InsertNode(G, X, &P);
}

adrNode AlokNode (int X){
/* Mengembalikan address hasil alokasi Simpul X. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=Nil,
dan Next(P)=Nil. Jika alokasi gagal, mengembalikan Nil. */
	adrNode P;

	P = (adrNode) malloc (sizeof(NodeGraph));
	if (P != NILL){
		Id(P) = X;
		NPred(P) = 0;
		Trail(P) = NILL;
		Next(P) = NILL;
	}

	return P;
}

void DealokNode (adrNode P){
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */
	free(P);
}

adrSuccNode AlokSuccNode (adrNode Pn){
/* Mengembalikan address hasil alokasi. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya
menghasilkan Pt, maka Succ(Pt)=Pn dan Next(Pt)=Nil. Jika
alokasi gagal, mengembalikan Nil. */
	adrSuccNode Pt;

	Pt = (adrSuccNode) malloc (sizeof(adrSuccNode));
	if (Pt != NILL){
		Succ(Pt) = Pn;
		Next(Pt) = NILL;
	}

	return Pt;
}

void DealokSuccNode (adrSuccNode P){
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */
	free(P);
}

adrNode SearchNode (Graph G, int X){
/* mengembalikan address simpul dengan Id=X jika sudah ada pada graph G,
Nil jika belum */
	adrNode Pn = First(G);
    while (Pn != NILL && (!isEqual(Pn, X))){
			Pn = Next(Pn);
    }

	return Pn;
}

adrSuccNode SearchEdge (Graph G, int prec, int succ){
/* mengembalikan address trailer yang menyimpan info busur (prec,succ)
jika sudah ada pada graph G, Nil jika belum */
	adrNode Pn = SearchNode(G, prec);
	if (Pn == NILL){
		return NILL;
	}

	adrSuccNode P = Trail(Pn);
	while (P != NILL && (!isEqual(Succ(P), succ))){
		P = Next(P);
	}

	return (P);
}

void InsertNode (Graph* G, int X, adrNode* Pn){
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil. */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G. */
/* F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi
address simpul X. Jika alokasi gagal, G tetap, Pn berisi Nil */
	*Pn = AlokNode(X);
        adrNode P = First(*G);
        if (P != NILL) {
            while (P != NILL) {
                P = Next(P);
            }

            Next(P) = *Pn;
        }

        else{
            First(*G) = *Pn;
        }
}

void InsertEdge (Graph* G, int prec, int succ){
/* Menambahkan busur dari prec menuju succ ke dalam G */
/* I.S. G, prec, succ terdefinisi. */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur
(prec,succ) ke G. Jika simpul prec/succ belum ada pada G,
tambahkan simpul tersebut dahulu. Jika sudah ada busur (prec,succ)
di G, maka G tetap. */
	if (SearchEdge(*G, prec, succ) == NILL){
		adrNode Pn = SearchNode(*G, prec);
		if (Pn == NILL){
			InsertNode(G, prec, &Pn);
		}

		adrNode Pt = SearchNode(*G, succ);
		if(Pt == NILL){
			InsertNode(G, succ, &Pt);
		}
        adrSuccNode P = Trail(Pn);
		if (P != NILL){
			while (Next(P) != NILL){
				P = Next(P);
			}

			Next(P) = AlokSuccNode(Pt);
		}

		else{
			Trail(Pn) = AlokSuccNode(Pt);
		}
	}
}

boolean isEqual (adrNode P, int X){
/* Memeriksa apakah Id adress P sama dengan X */
    return (Id(P) == X);
}
