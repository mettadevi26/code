#include <stdio.h>

// function login
int login() {
    int pinBenar = 1234;
    int pinInput;
    int percobaan = 0;

    while (percobaan < 3) {
        printf("Masukkan PIN: ");
        scanf("%d", &pinInput);

        if (pinInput == pinBenar) {
            printf("Login berhasil!\n\n");
            return 1; 
        } else {
            percobaan++;
            printf("PIN salah! Sisa: %d\n", 3 - percobaan);
        }
    }

    return 0; 
}

// function cek saldo
void cekSaldo(float saldo) {
    printf("Saldo Anda: %.2f\n", saldo);
}

// function setor
float setorUang(float saldo) {
    float jumlah;
    printf("Masukkan jumlah setor: ");
    scanf("%f", &jumlah);

    if (jumlah > 0) {
        saldo += jumlah;
        printf("Setor berhasil!\n");
    } else {
        printf("Jumlah tidak valid!\n");
    }

    return saldo;
}

// function tarik
float tarikUang(float saldo) {
    float jumlah;
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

    return saldo;
}

int main() {
    float saldo = 1000000;
    int pilihan;

    if (!login()) {
        printf("Kartu diblokir!\n");
        return 0;
    }

    while (1) {
        printf("\n=== MENU ATM ===\n");
        printf("1. Cek Saldo\n");
        printf("2. Setor Uang\n");
        printf("3. Tarik Uang\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            cekSaldo(saldo);
        }
        else if (pilihan == 2) {
            saldo = setorUang(saldo);
        }
        else if (pilihan == 3) {
            saldo = tarikUang(saldo);
        }
        else if (pilihan == 4) {
            printf("Terima kasih!\n");
            break;
        }
        else {
            printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}