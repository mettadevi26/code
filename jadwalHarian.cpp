#include <stdio.h>
#include <string.h>

#define MAX 100

struct Jadwal {
    int jam;
    int menit;
    char kegiatan[50];
};

struct Jadwal data[MAX];
int jumlah = 0;

// tambah jadwal
void tambahJadwal() {
    if (jumlah >= MAX) {
        printf("Jadwal penuh!\n");
        return;
    }

    int jam, menit;

    printf("Masukkan jam (0-23): ");
    scanf("%d", &jam);

    printf("Masukkan menit (0-59): ");
    scanf("%d", &menit);

    // VALIDASI BENTROK
    for (int i = 0; i < jumlah; i++) {
        if (data[i].jam == jam && data[i].menit == menit) {
            printf("Sudah ada jadwal di waktu %02d:%02d!\n", jam, menit);
            return; // langsung batal
        }
    }

    data[jumlah].jam = jam;
    data[jumlah].menit = menit;

    getchar();
    printf("Masukkan kegiatan: ");
    fgets(data[jumlah].kegiatan, sizeof(data[jumlah].kegiatan), stdin);

    jumlah++;
    printf("Jadwal berhasil ditambahkan!\n");
}

// tampil semua jadwal
void tampilJadwal() {
    if (jumlah == 0) {
        printf("Belum ada jadwal.\n");
        return;
    }

    printf("\n=== DAFTAR JADWAL ===\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%02d:%02d - %s",
               data[i].jam,
               data[i].menit,
               data[i].kegiatan);
    }
    printf("\n");
}

// cari berdasarkan jam
void cariJadwal() {
    int jam;
    printf("Masukkan jam yang dicari: ");
    scanf("%d", &jam);

    int found = 0;
    for (int i = 0; i < jumlah; i++) {
        if (data[i].jam == jam) {
            printf("%02d:%02d - %s",
                   data[i].jam,
                   data[i].menit,
                   data[i].kegiatan);
            found = 1;
        }
    }

    if (!found) {
        printf("Tidak ada jadwal di jam tersebut.\n");
    }
}

// hapus jadwal
void hapusJadwal() {
    int index;
    printf("Masukkan nomor jadwal yang ingin dihapus (1-%d): ", jumlah);
    scanf("%d", &index);

    if (index < 1 || index > jumlah) {
        printf("Input tidak valid!\n");
        return;
    }

    for (int i = index - 1; i < jumlah - 1; i++) {
        data[i] = data[i + 1];
    }

    jumlah--;
    printf("Jadwal berhasil dihapus!\n");
}

int main() {
    int pilihan;

    do {
        printf("\n=== MENU JADWAL HARIAN ===\n");
        printf("1. Tambah Jadwal\n");
        printf("2. Tampilkan Jadwal\n");
        printf("3. Cari Jadwal (berdasarkan jam)\n");
        printf("4. Hapus Jadwal\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: tambahJadwal(); break;
            case 2: tampilJadwal(); break;
            case 3: cariJadwal(); break;
            case 4: hapusJadwal(); break;
            case 0: printf("Keluar...\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 0);

    return 0;
}