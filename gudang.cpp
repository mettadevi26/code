#include <stdio.h>
#include <string.h>

#define MAX 100

struct Barang {
    char nama[50];
    int stok;
    float harga;
};

struct Barang gudang[MAX];
int jumlahBarang = 0;

// tambah barang
void tambahBarang() {
    printf("Nama barang: ");
    scanf(" %[^\n]", gudang[jumlahBarang].nama);

    printf("Stok: ");
    scanf("%d", &gudang[jumlahBarang].stok);

    printf("Harga: ");
    scanf("%f", &gudang[jumlahBarang].harga);

    jumlahBarang++;
    printf("Barang berhasil ditambahkan!\n");
}

// tampilkan semua barang
void tampilBarang() {
    if (jumlahBarang == 0) {
        printf("Gudang kosong!\n");
        return;
    }

    printf("\n=== DATA BARANG ===\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("%d. %s | Stok: %d | Harga: %.2f\n",
            i+1,
            gudang[i].nama,
            gudang[i].stok,
            gudang[i].harga);
    }
}

// cari barang
int cariBarang(char nama[]) {
    for (int i = 0; i < jumlahBarang; i++) {
        if (strcmp(gudang[i].nama, nama) == 0) {
            return i;
        }
    }
    return -1;
}

// update stok
void updateStok() {
    char nama[50];
    printf("Masukkan nama barang: ");
    scanf(" %[^\n]", nama);

    int index = cariBarang(nama);

    if (index == -1) {
        printf("Barang tidak ditemukan!\n");
        return;
    }

    int tambah;
    printf("Tambah stok: ");
    scanf("%d", &tambah);

    gudang[index].stok += tambah;
    printf("Stok berhasil diupdate!\n");
}

// hapus barang
void hapusBarang() {
    char nama[50];
    printf("Masukkan nama barang: ");
    scanf(" %[^\n]", nama);

    int index = cariBarang(nama);

    if (index == -1) {
        printf("Barang tidak ditemukan!\n");
        return;
    }

    for (int i = index; i < jumlahBarang - 1; i++) {
        gudang[i] = gudang[i + 1];
    }

    jumlahBarang--;
    printf("Barang berhasil dihapus!\n");
}

int main() {
    int pilihan;

    while (1) {
        printf("\n=== MENU GUDANG ===\n");
        printf("1. Tambah Barang\n");
        printf("2. Tampilkan Barang\n");
        printf("3. Update Stok\n");
        printf("4. Hapus Barang\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            tambahBarang();
        }
        else if (pilihan == 2) {
            tampilBarang();
        }
        else if (pilihan == 3) {
            updateStok();
        }
        else if (pilihan == 4) {
            hapusBarang();
        }
        else if (pilihan == 5) {
            printf("Keluar...\n");
            break;
        }
        else {
            printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}