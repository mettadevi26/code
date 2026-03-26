#include <stdio.h>

int main() {
    int detik;

    printf("Masukkan waktu (detik): ");
    scanf("%d", &detik);

    while (detik >= 0) {
        printf("Sisa waktu: %d detik\n", detik);
        detik--;
    }

    printf("Waktu habis!\n");

    return 0;
}