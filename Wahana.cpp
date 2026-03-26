#include <stdio.h>
#include <string.h>

#define MAX 50

// queue reguler
char reguler[MAX][50];
int frontR = 0, rearR = -1;

// queue fast track
char fast[MAX][50];
int frontF = 0, rearF = -1;

// enqueue reguler
void tambahReguler() {
    if (rearR >= MAX - 1) {
        printf("Antrian reguler penuh!\n");
        return;
    }

    rearR++;
    getchar();
    printf("Nama pengunjung: ");
    fgets(reguler[rearR], 50, stdin);

    printf("Masuk antrian reguler.\n");
}

// enqueue fast track
void tambahFast() {
    if (rearF >= MAX - 1) {
        printf("Antrian fast track penuh!\n");
        return;
    }

    rearF++;
    getchar();
    printf("Nama pengunjung: ");
    fgets(fast[rearF], 50, stdin);

    printf("Masuk antrian FAST TRACK.\n");
}

// tampil semua
void tampilAntrian() {
    printf("\n=== FAST TRACK ===\n");
    for (int i = frontF; i <= rearF; i++) {
        printf("%d. %s", i - frontF + 1, fast[i]);
    }

    printf("\n=== REGULER ===\n");
    for (int i = frontR; i <= rearR; i++) {
        printf("%d. %s", i - frontR + 1, reguler[i]);
    }
}

// proses naik wahana
void prosesWahana() {
    if (frontF <= rearF) {
        printf("FAST TRACK dipanggil: %s", fast[frontF]);
        frontF++;
    } else if (frontR <= rearR) {
        printf("REGULER dipanggil: %s", reguler[frontR]);
        frontR++;
    } else {
        printf("Tidak ada antrian.\n");
    }
}

int main() {
    int pilih;

    do {
        printf("\n=== SISTEM ANTREAN WAHANA ===\n");
        printf("1. Tambah Reguler\n");
        printf("2. Tambah Fast Track\n");
        printf("3. Lihat Antrian\n");
        printf("4. Panggil Pengunjung\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: tambahReguler(); break;
            case 2: tambahFast(); break;
            case 3: tampilAntrian(); break;
            case 4: prosesWahana(); break;
            case 0: printf("Keluar...\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }

    } while (pilih != 0);

    return 0;
}