#include <stdio.h>

int main() {
    int n, i, jumlah = 0;

    // Input dari user
    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    // Cetak deret dan hitung jumlah
    printf("Deret: ");
    for (i = 1; i <= n; i++) {
        printf("%d", i);
        if (i < n) {
            printf(" + ");
        }
        jumlah += i;
    }

    // Output hasil jumlah akhir
    printf(" = %d\n", jumlah);

    return 0;
}
