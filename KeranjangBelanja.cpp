#include <stdio.h>
#include <string.h>

#define MAX 100

struct Item {
    char nama[50];
    int harga;
    int qty;
};

struct Item cart[MAX];
int jumlahItem = 0;

// tambah barang
void tambahBarang() {
    if (jumlahItem >= MAX) {
        printf("Keranjang penuh!\n");
        return;
    }

    getchar(); // clear buffer

    printf("Nama barang: ");
    fgets(cart[jumlahItem].nama, sizeof(cart[jumlahItem].nama), stdin);

    printf("Harga: ");
    scanf("%d", &cart[jumlahItem].harga);

    printf("Jumlah: ");
    scanf("%d", &cart[jumlahItem].qty);

    jumlahItem++;
    printf("Barang berhasil ditambahkan!\n");
}

// tampilkan keranjang
void tampilKeranjang() {
    if (jumlahItem == 0) {
        printf("Keranjang kosong.\n");
        return;
    }

    int total = 0;

    printf("\n=== KERANJANG BELANJA ===\n");
    for (int i = 0; i < jumlahItem; i++) {
        int subtotal = cart[i].harga * cart[i].qty;
        total += subtotal;

        printf("%d. %s", i + 1, cart[i].nama);
        printf("   Harga: %d | Qty: %d | Subtotal: %d\n",
               cart[i].harga,
               cart[i].qty,
               subtotal);
    }

    printf("TOTAL: %d\n\n", total);
}

// hapus barang
void hapusBarang() {
    int index;

    printf("Masukkan nomor barang yang ingin dihapus: ");
    scanf("%d", &index);

    if (index < 1 || index > jumlahItem) {
        printf("Input tidak valid!\n");
        return;
    }

    for (int i = index - 1; i < jumlahItem - 1; i++) {
        cart[i] = cart[i + 1];
    }

    jumlahItem--;
    printf("Barang berhasil dihapus!\n");
}

// hitung total saja
void hitungTotal() {
    int total = 0;

    for (int i = 0; i < jumlahItem; i++) {
        total += cart[i].harga * cart[i].qty;
    }

    printf("Total belanja: %d\n", total);
}

int main() {
    int pilih;

    do {
        printf("\n=== MENU KERANJANG ===\n");
        printf("1. Tambah Barang\n");
        printf("2. Lihat Keranjang\n");
        printf("3. Hapus Barang\n");
        printf("4. Hitung Total\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: tambahBarang(); break;
            case 2: tampilKeranjang(); break;
            case 3: hapusBarang(); break;
            case 4: hitungTotal(); break;
            case 0: printf("Keluar...\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }

    } while (pilih != 0);

    return 0;
}