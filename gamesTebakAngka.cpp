#include <stdio.h>
int main () {
    int secretnumber = 12;
    int angka;

    while (angka != 99) {
    printf ("masukkan tebakan anda : ");
    scanf ("%d" , &angka);

    if (angka == 99) {
        printf ("end game. Angka yang benar adalah 12");
        break;
    }

    if (angka > secretnumber) {
        printf ("angka terlalu besar, coba lebih rendah \n");
    }
    
    if (angka < secretnumber) {
        printf ("angka terlalu kecil, coba lebih tinggi \n");
    }

    if (angka == secretnumber) {
        printf ("angka anda benar");
        break;
    }

    }

}