#include <stdlib.h>
#include <stdio.h>
#include "circular_queue.h"

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q) {
    return Q.HEAD == NIL && Q.TAIL == NIL;
}
boolean IsFullQueue (Queue Q) {
    return LengthQueue(Q) == Q.MaxElQueue;
}
int LengthQueue (Queue Q) {
    if (IsEmptyQueue(Q)) {
        return 0;
    }
    else if (Q.HEAD >= Q.TAIL) {
        return Q.MaxElQueue + Q.TAIL - Q.HEAD;
    }
    else {
        return Q.TAIL - Q.HEAD;
    }
}

int MaxLengthQueue (Queue Q) {
    return Q.MaxElQueue;
}

/* *** Kreator *** */
Queue CreateQueue (int Max) {
    Queue Q;
    Q.Tab = (ElTypeQueue *) malloc (Max * sizeof(ElTypeQueue));
    Q.HEAD = NIL;
    Q.TAIL = NIL;
    Q.MaxElQueue = Max;
    return Q;
}

/* *** Destruktor *** */
void DeleteQueue (Queue * Q) {
    Q->MaxElQueue = 0;
    free(Q->Tab);
}

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, ElTypeQueue X) {
    if (IsEmptyQueue(*Q)) {
        Q->HEAD = 0;
        Q->TAIL = 0;
    }
    Q->Tab[Q->TAIL] = X;
    Q->TAIL++;
    if (Q->TAIL == Q->MaxElQueue) {
        Q->TAIL = 0;
    }
}
ElTypeQueue Dequeue (Queue * Q) {
    ElTypeQueue ret = Q->Tab[Q->HEAD];
    Q->HEAD++;
    if (Q->HEAD == Q->MaxElQueue) {
        Q->HEAD = 0;
    }
    if (Q->HEAD == Q->TAIL) {
        Q->HEAD = NIL;
        Q->TAIL = NIL;
    }
    return ret;
}
ElTypeQueue FrontQueue (Queue Q) {
    return Q.Tab[Q.HEAD];
}

ElTypeQueue BacktQueue (Queue Q) {
    return Q.Tab[Q.TAIL];
}

/* *** Utilitas *** */
Queue CopyQueue (Queue Q) {
    Queue new = CreateQueue(Q.MaxElQueue);
    if (!IsEmptyQueue(Q)) {
        int tail = Q.HEAD;
        while (LengthQueue(new) != LengthQueue(Q)) {
            Enqueue(&new, Q.Tab[tail]);
            tail = (tail + 1) % Q.MaxElQueue;
        }
    }
    return new;
}

void PrintQueue(Queue Q) {
    Queue Q2 = CopyQueue(Q);
    ElTypeQueue hasil;
    int i = 0;
    while (i < Q.MaxElQueue) {
        printf("%d. {{%s, %d, %d, %d}, %d, %d, %d}\n" , i+1, FrontQueue(Q).NKQ.Nama, FrontQueue(Q).NKQ.harga, FrontQueue(Q).NKQ.kodeJenis, FrontQueue(Q).NKQ.jumlah, FrontQueue(Q).invoice, FrontQueue(Q).order_id, FrontQueue(Q).pemesanan);
        i++;
        hasil = Dequeue(&Q);
    }
}

void PrintQueueCheckOrder(Queue Q) {
    Queue Q2 = CopyQueue(Q);
    ElTypeQueue hasil;
    int i = 0;
    while (i < Q.MaxElQueue) {
        printf("%d. %s\n" , i+1, FrontQueue(Q).NKQ.Nama);
        i++;
        hasil = Dequeue(&Q);
    }
}
