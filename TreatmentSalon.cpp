#include <stdio.h>

int main () {
    int pilihan, n;
    int total = 0;
    printf ("Masukkan berapa banyak treatment yang ingin anda lakukan = ");
    scanf ("%d", &n);

for (int i = 1; i <= n; i++) {
    printf ("==PILIHAN TREATMENT==\n");
    printf ("1. Creambath\n");
    printf ("2. Haircut\n");
    printf ("3. Hair Coloring\n");
    printf ("4. Menicure Pedicure\n");
    printf ("5. Hairwash & blow/catok\n");
    printf ("Masukkan pilihan treatment yang anda mau : ");
    scanf ("%d", &pilihan);

    int creambath = 250000, haircut = 120000, haircoloring = 1500000, menicurepedicure = 200000, hairwash = 100000;

    if (pilihan == 1) {
        total += creambath;
    } else if (pilihan == 2) {
        total += haircut;
    } else if (pilihan == 3) {
        total += haircoloring;
    } else if (pilihan == 4) {
        total += menicurepedicure;
    } else if (pilihan == 5) {
        total += hairwash;
    } else {
        printf ("pilihan anda tidak valid");
    }
}
    printf ("Total harga treatment anda = Rp %d", total);
}