/* File : queuelist.c */

#include "queuelist.h"
#include <stdlib.h>

/* Prototype manajemen memori */
void Alokasi (address *P, int order_id, int pemesanan, int invoice, char *komponen1, char *komponen2, char *komponen3, char *komponen4, char *komponen5, char *komponen6, char *komponen7, char *komponen8)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    *P = (address) malloc(sizeof(ElmtQueue));
    if (*P!=Nil){
        order_id(*P) = order_id;
        pemesanan(*P) = pemesanan;
        invoice(*P) = invoice;
        P->T[0].komponen = komponen1;
        P->T[1].komponen = komponen2;
        P->T[2].komponen = komponen3;
        P->T[3].komponen = komponen4;
        P->T[4].komponen = komponen5;
        P->T[5].komponen = komponen6;
        P->T[6].komponen = komponen7;
        P->T[7].komponen = komponen8;
        Next(*P) = Nil;
    }
}

void Dealokasi (address  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}

boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
    return(Head(Q)==Nil && Tail(Q)==Nil);
}

int NbElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
    int count = 0;
    if (!IsEmpty(Q)){
        address P = Head(Q);
        while(P!=Nil){
            count++;
            P = Next(P);
        }
    }
    return count;
}

/*** Kreator ***/
void CreateEmpty(Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
    Head(*Q) = 0;
    Tail(*Q) = 0;
}

/*** Primitif Enqueue/Dequeue ***/
void Enqueue (Queue * Q,  int order_id, int pemesanan, int invoice, char *komponen1, char *komponen2, char *komponen3, char *komponen4, char *komponen5, char *komponen6, char *komponen7, char *komponen8)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
    address P;
    Alokasi(&P, order_id, pemesanan, invoice, komponen1, komponen2, komponen3, komponen4, komponen5, komponen6, komponen7, komponen8);
    if (P!=Nil){
        if (IsEmpty(*Q)){
            Head(*Q) = P;
            Tail(*Q) = P;
        } else {
            Next(Tail(*Q)) = P;
            Tail(*Q) = P;
        }
    }
}

void Dequeue(Queue * Q, infotype * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    *X = InfoHead(*Q);
    address P = Head(*Q);
    if (NbElmt(*Q)==1){
        Tail(*Q) = Nil;
    }
    Head(*Q) = Next(Head(*Q));
    Dealokasi(P);
}