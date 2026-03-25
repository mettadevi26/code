#include <stdio.h>

int main() {
    int kursi[10] = {0}; // 0 = kosong, 1 = terisi
    int pilihan;

    while (1) {
        printf("\n=== DAFTAR KURSI ===\n");
        for (int i = 0; i < 10; i++) {
            if (kursi[i] == 0)
                printf("Kursi %d: Kosong\n", i + 1);
            else
                printf("Kursi %d: Terisi\n", i + 1);
        }

        printf("\nPilih nomor kursi (1-10, 0 untuk keluar): ");
        scanf("%d", &pilihan);

        if (pilihan == 0) {
            printf("Terima kasih!\n");
            break;
        }

        // validasi input
        if (pilihan < 1 || pilihan > 10) {
            printf("Nomor kursi tidak valid!\n");
            continue;
        }

        // cek apakah kursi sudah terisi
        if (kursi[pilihan - 1] == 1) {
            printf("Kursi sudah terisi, pilih yang lain!\n");
        } else {
            kursi[pilihan - 1] = 1;
            printf("Kursi %d berhasil dipesan!\n", pilihan);
        }
    }

    return 0;
}