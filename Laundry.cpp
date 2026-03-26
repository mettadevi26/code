#include <stdio.h>
#include <string.h>

#define MAX 100

struct Laundry {
    char nama[50];
    float berat;
    int status;
};

struct Laundry data[MAX];
int jumlah = 0;

// tampil status dalam teks
char* getStatus(int status) {
    if (status == 0) return "Antri";
    else if (status == 1) return "Dicuci";
    else if (status == 2) return "Dikeringkan";
    else return "Selesai";
}

// tambah cucian
void tambahLaundry() {
    if (jumlah >= MAX) {
        printf("Data penuh!\n");
        return;
    }

    getchar();
    printf("Nama pelanggan: ");
    fgets(data[jumlah].nama, sizeof(data[jumlah].nama), stdin);

    printf("Berat (kg): ");
    scanf("%f", &data[jumlah].berat);

    data[jumlah].status = 0; // default antri
    jumlah++;

    printf("Laundry berhasil ditambahkan!\n");
}

// tampil semua
void tampilLaundry() {
    if (jumlah == 0) {
        printf("Belum ada data.\n");
        return;
    }

    printf("\n=== DATA LAUNDRY ===\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%d. %s", i + 1, data[i].nama);
        printf("   Berat: %.2f kg | Status: %s\n",
               data[i].berat,
               getStatus(data[i].status));
    }
}

// proses laundry (naik status)
void prosesLaundry() {
    int index;
    printf("Pilih nomor laundry: ");
    scanf("%d", &index);

    if (index < 1 || index > jumlah) {
        printf("Input tidak valid!\n");
        return;
    }

    if (data[index - 1].status < 3) {
        data[index - 1].status++;
        printf("Status diperbarui menjadi: %s\n",
               getStatus(data[index - 1].status));
    } else {
        printf("Laundry sudah selesai!\n");
    }
}

// ambil laundry (hapus)
void ambilLaundry() {
    int index;
    printf("Pilih nomor laundry yang diambil: ");
    scanf("%d", &index);

    if (index < 1 || index > jumlah) {
        printf("Input tidak valid!\n");
        return;
    }

    if (data[index - 1].status != 3) {
        printf("Laundry belum selesai!\n");
        return;
    }

    for (int i = index - 1; i < jumlah - 1; i++) {
        data[i] = data[i + 1];
    }

    jumlah--;
    printf("Laundry sudah diambil!\n");
}

int main() {
    int pilih;

    do {
        printf("\n=== SISTEM LAUNDRY ===\n");
        printf("1. Tambah Laundry\n");
        printf("2. Lihat Data\n");
        printf("3. Proses Laundry\n");
        printf("4. Ambil Laundry\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: tambahLaundry(); break;
            case 2: tampilLaundry(); break;
            case 3: prosesLaundry(); break;
            case 4: ambilLaundry(); break;
            case 0: printf("Keluar...\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }

    } while (pilih != 0);

    return 0;
}