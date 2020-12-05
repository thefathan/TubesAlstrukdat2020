#include "../Point/point.h"
#include "boolean.h"

#ifndef alamat_H
#define alamat_H

typedef char jns;
typedef struct{
    POINT titik;
    jns jenis;
} Alamat;

// SELEKTOR
#define Titik(A)        (A).titik
#define Jenis(A)        (A).jenis

// KONSTRUKTOR
void MakeAlamat(Alamat *A, POINT T, jns J);
// Membuat titik-titik alamat pada map

#endif // alamat_H
