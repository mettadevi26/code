#include <stdio.h>

int main () {
    int angka [10];

    printf ("Masukkan 10 angka integer yang ingin anda sortir.\n");
    for (int i = 0; i < 10; i++) {
        printf ("Masukkan angka ke-%d = ", i + 1);
        scanf ("%d", &angka[i]);
    }

    printf ("Daftar bilangan genap yang anda input: ");
    for (int i = 0; i < 10; i++) {
        if (angka [i] % 2 == 0) {
            printf ("%d ", angka [i]);
        } 
    }

    printf("\nDaftar bilangan ganjil yang anda input: ");
    for(int i = 0; i < 10; i++) {
        if(angka[i] % 2 != 0) {
            printf("%d ", angka[i]);
        }
    }
return 0;
}