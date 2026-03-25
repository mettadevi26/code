#include <stdio.h>

// function hitung total
float hitungBiaya(int lamaSewa, int lamaPakai, float harga, float denda, float *diskon, int *telat) {
    float total = lamaSewa * harga;

    // diskon
    if (lamaSewa >= 10) {
        *diskon = 0.20 * total;
    } else if (lamaSewa >= 5) {
        *diskon = 0.10 * total;
    } else {
        *diskon = 0;
    }

    total -= *diskon;

    // denda
    if (lamaPakai > lamaSewa) {
        *telat = lamaPakai - lamaSewa;
        total += (*telat) * denda;
    } else {
        *telat = 0;
    }

    return total;
}

// function cetak struk (void)
void cetakStruk(char nama[], int lamaSewa, int lamaPakai,
                float harga, float diskon, int telat, float denda, float total) {

    printf("\n===== STRUK SEWA MOBIL =====\n");
    printf("Nama           : %s\n", nama);
    printf("Lama sewa      : %d hari\n", lamaSewa);
    printf("Lama pakai     : %d hari\n", lamaPakai);
    printf("Harga/hari     : %.0f\n", harga);

    printf("Subtotal       : %.0f\n", lamaSewa * harga);
    printf("Diskon         : -%.0f\n", diskon);

    if (telat > 0) {
        printf("Denda (%d hari): +%.0f\n", telat, telat * denda);
    } else {
        printf("Denda          : 0\n");
    }

    printf("----------------------------\n");
    printf("TOTAL BAYAR    : %.0f\n", total);
    printf("============================\n");
}

int main() {
    char nama[50];
    int lamaSewa, lamaPakai, telat;
    float harga = 300000;
    float denda = 50000;
    float diskon, total;

    printf("Nama penyewa: ");
    scanf(" %[^\n]", nama);

    printf("Lama sewa (hari): ");
    scanf("%d", &lamaSewa);

    printf("Lama pemakaian (hari): ");
    scanf("%d", &lamaPakai);

    total = hitungBiaya(lamaSewa, lamaPakai, harga, denda, &diskon, &telat);

    // panggil cetak struk
    cetakStruk(nama, lamaSewa, lamaPakai, harga, diskon, telat, denda, total);

    return 0;
}