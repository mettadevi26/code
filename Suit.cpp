#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player, komputer;
    char ulang;

    srand(time(NULL)); // biar random beda tiap run

    do {
        printf("\n=== GUNTING BATU KERTAS ===\n");
        printf("1. Gunting\n2. Batu\n3. Kertas\n");
        printf("Pilih: ");
        scanf("%d", &player);

        // validasi input
        if (player < 1 || player > 3) {
            printf("Pilihan tidak valid!\n");
            continue;
        }

        komputer = (rand() % 3) + 1;

        printf("Pilihan komputer: ");
        if (komputer == 1) printf("Gunting\n");
        else if (komputer == 2) printf("Batu\n");
        else printf("Kertas\n");

        // hasil
        if (player == komputer) {
            printf("Hasil: SERI\n");
        }
        else if ((player == 1 && komputer == 3) ||
                 (player == 2 && komputer == 1) ||
                 (player == 3 && komputer == 2)) {
            printf("Hasil: KAMU MENANG!\n");
        }
        else {
            printf("Hasil: KOMPUTER MENANG!\n");
        }

        printf("Main lagi? (y/n): ");
        scanf(" %c", &ulang);

    } while (ulang == 'y' || ulang == 'Y');

    printf("Terima kasih sudah bermain!\n");
    return 0;
}