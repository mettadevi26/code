#include <stdio.h>

struct Mahasiswa {
    char nama[50];
    float nilai;
};

int main() {
    struct Mahasiswa mhs[3];
    float total = 0;

    for(int i = 0; i < 3; i++) {
        printf("Nama: ");
        scanf("%s", mhs[i].nama);

        printf("Nilai: ");
        scanf("%f", &mhs[i].nilai);

        total += mhs[i].nilai;
    }

    printf("\nRata-rata: %.2f\n", total/3);

    return 0;
}