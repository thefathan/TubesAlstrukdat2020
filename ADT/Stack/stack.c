#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack CreateEmptyStack()
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Stack S;
    S.T = (Sinfotype *) malloc(InitialSizeStack * sizeof(Sinfotype));
    S.TOP = Nil;
    return S;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsStackEmpty(Stack S)
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
{
    return S.TOP == Nil;
}

bool IsStackFull(Stack S)
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
{
    return S.TOP == MaxElStack;
}
/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, Sinfotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
{
    if (!IsStackFull(*S)) {
        S->TOP++;
        S->T[S->TOP] = X;
    }
}
void Pop(Stack *S, Sinfotype *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    (*X) = S->T[S->TOP];
    S->TOP--;
}

void ForcePush(Stack *S, Sinfotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S mungkin penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1
        Apabila S penuh, buang element paling bawah dari S dan masukkan X sebagai TOP
        Contoh: S berisi a b c d e f g h i j, setelah melakukan ForcePush(S, "k")
        S berisi b c d e f g h i j k */
{
    int idx;
    if (!IsStackFull(*S))
    {
        Push(S, X);
    }
    else
    {
        for (idx = 0; idx < S->TOP - 1; idx++)
        {
            S->T[idx] = S->T[idx + 1];
        }
        S->T[S->TOP - 1] = X;
    }
}


Sinfotype GetElmtStack(Stack S) {
    return S.T[S.TOP];
}

void PrintStack(Stack *S) 
/* Mencetak elemen stack dengan urutan TOP paling bawah */
{
    Stack S1, S2; Sinfotype isi;

    S1 = *S;
    S2 = CreateEmptyStack();
    while (!IsStackEmpty(S1)) {
        Pop(&S1, &isi);
        Push(&S2, isi);
    }
    int i = 1;
    while(!IsStackEmpty(S2)) {
        printf("%d. %s, %d, %d\n", i, GetElmtStack(S2).Nama, GetElmtStack(S2).harga, GetElmtStack(S2).kodeJenis);
        Pop(&S2, &isi);
        i++;
    }
}

void PrintStackAddComponent(Stack *S) 
/* Mencetak elemen stack dengan urutan TOP paling bawah */
{
    Stack S1, S2; Sinfotype isi;

    S1 = *S;
    S2 = CreateEmptyStack();
    while (!IsStackEmpty(S1)) {
        Pop(&S1, &isi);
        Push(&S2, isi);
    }
    int i = 1;
    while(!IsStackEmpty(S2)) {
        printf("%d. %s\n", i, GetElmtStack(S2).Nama);
        Pop(&S2, &isi);
        i++;
    }
}

bool IsStackSama(Stack *S1, Stack *S2) {
    Sinfotype elemen1, elemen2;
    for (int i = 1; i <= MaxElStack; i++) {
        Pop(S1, &elemen1);
        Pop(S2, &elemen2);
        if(strcmp(elemen1.Nama, elemen2.Nama) == 0) {
            return true;
        }
    }
    return false;
}