/* File : queuelist.h */

#ifndef _QUEUELIST_H
#define _QUEUELIST_H
#include "boolean.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef int infotype;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * address;



typedef char Komponen[255];
typedef struct {
    Komponen Nama;
    int harga;
    int kodeJenis;
    int jumlah;
} Komp;


typedef struct tElmtQueue {
    int order_id;
    int pemesanan;
    int invoice;
    Komp *T;
    address Next;
} ElmtQueue;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
	address HEAD;  /* alamat penghapusan */
	address TAIL;  /* alamat penambahan */
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info
#define Prio(P) (P)->Prio
#define nomor_order(P) (P)-> nomor_order
#define nomor_pelanggan(P) (P)->nomor_pelanggan
#define invoice(P) (P)->invoice
#define T(P) (P)->T

/* Prototype manajemen memori */
void Alokasi (address *P, int order_id, int pemesanan, int invoice, char *komponen1, char *komponen2, char *komponen3, char *komponen4, char *komponen5, char *komponen6, char *komponen7, char *komponen8);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X,
        Next(P)=Nil, dan Prio(P)=prio */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty (Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk (i.e. Head(Q) = Nil dan Tail(Q) = Nil) */
/*** Primitif Add/Delete ***/
void Enqueue (Queue * Q,  int order_id, int pemesanan, int invoice, char *komponen1, char *komponen2, char *komponen3, char *komponen4, char *komponen5, char *komponen6, char *komponen7, char *komponen8);
/* Proses: Mengalokasi X dan menambahkan X pada posisi setelah element dengan 
   prioritas yang lebih tinggi/sama, dan sebelum element dengan prioritas yang 
   lebih rendah jika alokasi berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X diletakkan setelah setelah element dengan prioritas yang lebih 
   tinggi/sama, dan sebelum element dengan prioritas yang lebih rendah.
   Apabila X diletakkan di posisi terakhir, maka TAIL = element X. */
void Dequeue (Queue * Q, infotype * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

#endif
