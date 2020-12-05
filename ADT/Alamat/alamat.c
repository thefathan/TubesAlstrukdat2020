#include <stdio.h>
#include "alamat.h"


void MakeAlamat(Alamat *A, POINT T, jns J){
// Membuat titik-titik alamat pada map
    Absis(Titik(*A)) = Absis(T);
    Ordinat(Titik(*A)) = Ordinat(T);
    Jenis(*A) = J;
}
