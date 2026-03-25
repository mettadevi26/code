#include <stdio.h>

int main() {
    float kecepatan, waktu;

    printf("Kecepatan (km/jam): ");
    scanf("%f", &kecepatan);

    printf("Waktu (jam): ");
    scanf("%f", &waktu);

    printf("Jarak: %.2f km\n", kecepatan * waktu);

    return 0;
}