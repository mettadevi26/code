#include <stdio.h>

int TarifDasar = 5000;

//a. biaya parkir 1 kendaraan
int biayaParkir (int lamaParkir, int jenisKendaraan) {
    int tarifPerJam;
    int tarifTotal;
    if (jenisKendaraan == 0) {
        tarifPerJam = TarifDasar;  
    } else if (jenisKendaraan == 1) {
        tarifPerJam = 0.5 * TarifDasar;
    } else if (jenisKendaraan == 2) {
        tarifPerJam = 2 * TarifDasar;
    } else {
        return 0;
    }

    tarifTotal = tarifPerJam * lamaParkir;

    if (lamaParkir >= 5) {
        tarifTotal = tarifTotal * 0.9;
    }

    return tarifTotal;
}

//b. menghitung total seluruh biaya parkir
int totalBiaya (int biaya [], int jumlahKendaraan) {
    int total = 0;
    for (int i = 0; i < jumlahKendaraan; i++) {
        total += biaya [i];
    }

    return total;
}

//c. cetak struk
void cetakStruk (char namaPelanggan[], int biaya[], int jumlahKendaraan, int total, int lamaParkir[], int jenisKendaraan[] ) {
    FILE *file;
    file = fopen("struk_parkir.txt", "a");  

    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("\nSTRUK PARKIR\n");
    printf("Nama Pelanggan : %s\n", namaPelanggan);
    printf("Jumlah kendaraan : %d\n\n", jumlahKendaraan);

    fprintf(file, "\nSTRUK PARKIR\n");
    fprintf(file, "Nama Pelanggan : %s\n", namaPelanggan);
    fprintf(file, "Jumlah kendaraan : %d\n\n", jumlahKendaraan);

    for (int i = 0; i < jumlahKendaraan; i++) {
        printf("Kendaraan ke-%d\n", i + 1);
        fprintf(file, "Kendaraan ke-%d\n", i + 1);

        if (jenisKendaraan[i] == 0) {
            printf("Jenis kendaraan : Mobil\n");
            fprintf(file, "Jenis kendaraan : Mobil\n");
        } else if (jenisKendaraan[i] == 1) {
            printf("Jenis kendaraan : Motor\n");
            fprintf(file, "Jenis kendaraan : Motor\n");
        } else if (jenisKendaraan[i] == 2) {
            printf("Jenis kendaraan : Truk\n");
            fprintf(file, "Jenis kendaraan : Truk\n");
        }

        printf("Lama Parkir : %d jam\n", lamaParkir[i]);
        printf("Biaya Parkir : %d\n\n", biaya[i]);

        fprintf(file, "Lama Parkir : %d jam\n", lamaParkir[i]);
        fprintf(file, "Biaya Parkir : %d\n\n", biaya[i]);
    }

    printf("Total Biaya Parkir seluruh kendaraan anda : %d\n", total);
    fprintf(file, "Total Biaya Parkir seluruh kendaraan anda : %d\n", total);
    fprintf(file, "------------------------------------------\n");

    fclose(file);
}

// fungsi main
int main () {
    char namaPelanggan [50];
    int jumlahKendaraan;

    int jenisKendaraan[3]; 
    int lamaParkir[3];
    int biaya[3];

    printf ("Masukkan nama anda = ");
    scanf (" %s", namaPelanggan);

    printf ("Masukkan jumlah kendaraan anda (maks 3) : ");
    scanf ("%d" , &jumlahKendaraan);
    if (jumlahKendaraan < 1 || jumlahKendaraan > 3) {
        printf ("Jumlah kendaraan tidak valid.\n");
        return 0;
    }

    for (int i = 0; i < jumlahKendaraan; i++){
    printf ("Masukkan jenis kendaraan ke-%d anda.\n", i + 1);
    printf ("ket : 0 = mobil, 1 = motor, 2 = truk = ");
    scanf ("%d" , &jenisKendaraan[i]);

    printf ("Masukkan lama parkir anda (dalam jam) = ");
    scanf ("%d", &lamaParkir[i]);

    biaya [i] = biayaParkir(lamaParkir [i], jenisKendaraan[i]);
    }

    int totalBiayaParkir = totalBiaya (biaya, jumlahKendaraan);
    cetakStruk (namaPelanggan, biaya, jumlahKendaraan, totalBiayaParkir, lamaParkir, jenisKendaraan); 

    return 0;
}