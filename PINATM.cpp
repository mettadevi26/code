#include <stdio.h>

int main() {
    int pinBenar = 1234;
    int pinInput;
    int percobaan = 0;

    float saldo = 1000000; // saldo awal
    int pilihan;
    float jumlah;

    // LOGIN PIN
    while (percobaan < 3) {
        printf("Masukkan PIN: ");
        scanf("%d", &pinInput);

        if (pinInput == pinBenar) {
            printf("Login berhasil!\n\n");
            break;
        } else {
            percobaan++;
            printf("PIN salah! Sisa: %d\n", 3 - percobaan);
        }
    }

    // Kalau gagal 3x
    if (percobaan == 3) {
        printf("Kartu diblokir!\n");
        return 0;
    }

    // MENU ATM
    while (1) {
        printf("\n=== MENU ATM ===\n");
        printf("1. Cek Saldo\n");
        printf("2. Setor Uang\n");
        printf("3. Tarik Uang\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            printf("Saldo Anda: %.2f\n", saldo);
        }
        else if (pilihan == 2) {
            printf("Masukkan jumlah setor: ");
            scanf("%f", &jumlah);

            if (jumlah > 0) {
                saldo += jumlah;
                printf("Setor berhasil!\n");
            } else {
                printf("Jumlah tidak valid!\n");
            }
        }
        else if (pilihan == 3) {
            printf("Masukkan jumlah tarik: ");
            scanf("%f", &jumlah);

            if (jumlah > saldo) {
                printf("Saldo tidak cukup!\n");
            } else if (jumlah <= 0) {
                printf("Jumlah tidak valid!\n");
            } else {
                saldo -= jumlah;
                printf("Penarikan berhasil!\n");
            }
        }
        else if (pilihan == 4) {
            printf("Terima kasih telah menggunakan ATM.\n");
            break;
        }
        else {
            printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}