#include <stdio.h>

int main() {
    int lantaiSekarang = 1;
    int tujuan;

    while (1) {
        printf("\nLift sekarang di lantai: %d\n", lantaiSekarang);
        printf("Masukkan tujuan (1-10, 0 untuk keluar): ");
        scanf("%d", &tujuan);

        if (tujuan == 0) {
            printf("Lift dimatikan.\n");
            break;
        }

        if (tujuan < 1 || tujuan > 10) {
            printf("Lantai tidak valid!\n");
            continue;
        }

        // naik
        if (tujuan > lantaiSekarang) {
            printf("Lift naik...\n");
            while (lantaiSekarang < tujuan) {
                lantaiSekarang++;
                printf("Sekarang di lantai %d\n", lantaiSekarang);
            }
        }
        // turun
        else if (tujuan < lantaiSekarang) {
            printf("Lift turun...\n");
            while (lantaiSekarang > tujuan) {
                lantaiSekarang--;
                printf("Sekarang di lantai %d\n", lantaiSekarang);
            }
        }
        else {
            printf("Anda sudah di lantai tujuan.\n");
        }

        printf("Pintu terbuka di lantai %d\n", lantaiSekarang);
    }

    return 0;
}