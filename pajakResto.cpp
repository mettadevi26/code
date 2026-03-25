#include <stdio.h>
#include <math.h>

int main() {
    float hargaAwal, total, ppn;
    int metode;
    int totalBayar;

    printf("Masukkan total harga makanan: ");
    scanf("%f", &hargaAwal);

    // hitung PPN 10%
    ppn = 0.10 * hargaAwal;
    total = hargaAwal + ppn;

    printf("\nPPN (10%%): %.2f\n", ppn);
    printf("Total sebelum pembulatan: %.2f\n", total);

    // pilih metode pembayaran
    printf("\nMetode pembayaran:\n");
    printf("1. Cash\n");
    printf("2. Debit\n");
    printf("Pilih: ");
    scanf("%d", &metode);

    if (metode == 1) {
        int sisa = (int)total % 1000;

        if (sisa == 0) {
            totalBayar = total;
        }
        else if (sisa <= 500) {
            totalBayar = ((int)total / 1000) * 1000 + 500;
        }
        else {
            totalBayar = ((int)total / 1000) * 1000 + 1000;
        }

        printf("Total bayar (cash, dibulatkan): %d\n", totalBayar);
    }
    else if (metode == 2) {
        printf("Total bayar (debit): %.2f\n", total);
    }
    else {
        printf("Metode tidak valid!\n");
    }

    return 0;
}