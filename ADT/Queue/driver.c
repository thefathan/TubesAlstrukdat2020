#include <stdlib.h>
#include <stdio.h>
#include "circular_queue.c"


int main() {
    Queue Q;

    // for (int i = 0; i < 8; i++) {
    //     NamaKomponenQueue NKQ = {"AMD Zotac", 200, 2, 1};
    // }

    Q = CreateQueue(100);
    ElType Y = {{" ", 0, 0, 0}, 0, 0, 0};
    Enqueue(&Q,Y);
    for (int i = 0; i < 20; i++) {
        ElType X = {{"AMD Zotac", 200, 2, 1}, i+1, i+20, 2000};
        // printf("%d\n", X.NKQ.harga);
        Enqueue(&Q,X);
    }

    PrintQueue(Q);
    PrintQueueCheckOrder(Q);


        


}
