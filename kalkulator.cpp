#include <stdio.h>

// function operasi
float tambah(float a, float b) {
    return a + b;
}

float kurang(float a, float b) {
    return a - b;
}

float kali(float a, float b) {
    return a * b;
}

float bagi(float a, float b) {
    if (b == 0) {
        printf("Error: pembagian dengan nol!\n");
        return 0;
    }
    return a / b;
}

int main() {
    float a, b, hasil;
    int pilihan;

    printf("Masukkan angka pertama: ");
    scanf("%f", &a);

    printf("Masukkan angka kedua: ");
    scanf("%f", &b);

    printf("\nPilih operasi:\n");
    printf("1. Tambah\n");
    printf("2. Kurang\n");
    printf("3. Kali\n");
    printf("4. Bagi\n");
    printf("Pilih: ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        hasil = tambah(a, b);
    }
    else if (pilihan == 2) {
        hasil = kurang(a, b);
    }
    else if (pilihan == 3) {
        hasil = kali(a, b);
    }
    else if (pilihan == 4) {
        hasil = bagi(a, b);
    }
    else {
        printf("Pilihan tidak valid!\n");
        return 0;
    }

    printf("Hasil: %.2f\n", hasil);

    return 0;
}