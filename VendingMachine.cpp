#include <stdio.h>

#define MAX 5

struct Barang {
    char nama[20];
    int harga;
    int stok;
};

struct Barang mesin[MAX] = {
    {"CocaCola", 5000, 3},
    {"Sprite", 5000, 2},
    {"Fanta", 5000, 0},   // stok kosong
    {"Aqua", 3000, 5},
    {"TehBotol", 4000, 1}
};

// tampil menu
void tampilMenu() {
    printf("\n=== VENDING MACHINE ===\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d. %s - Rp%d (Stok: %d)\n",
               i + 1,
               mesin[i].nama,
               mesin[i].harga,
               mesin[i].stok);
    }
    printf("0. Keluar\n");
}

// beli barang
void beliBarang(int pilihan) {
    if (pilihan < 1 || pilihan > MAX) {
        printf("Pilihan tidak valid!\n");
        return;
    }

    // cek stok
    if (mesin[pilihan - 1].stok == 0) {
        printf("Maaf, %s habis!\n", mesin[pilihan - 1].nama);
    } else {
        mesin[pilihan - 1].stok--;
        printf("Kamu mendapatkan %s\n", mesin[pilihan - 1].nama);
    }
}

int main() {
    int pilih;

    do {
        tampilMenu();
        printf("Pilih barang: ");
        scanf("%d", &pilih);

        if (pilih != 0) {
            beliBarang(pilih);
        }

    } while (pilih != 0);

    printf("Terima kasih!\n");
    return 0;
}