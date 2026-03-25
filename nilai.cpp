#include <stdio.h>

void analisisNilai(int arr[], int n, float *rata, int *lulus) {
    int total = 0;
    *lulus = 0;

    for(int i = 0; i < n; i++) {
        total += arr[i];

        if(arr[i] >= 60) {
            (*lulus)++;
        } else {
            arr[i] = 60; // remedial
        }
    }

    *rata = (float) total / n;
}

int main() {
    int nilai[] = {50, 70, 40, 90, 55};
    int n = 5;

    float rata;
    int jumlahLulus;

    analisisNilai(nilai, n, &rata, &jumlahLulus);

    printf("Rata-rata: %.2f\n", rata);
    printf("Jumlah lulus: %d\n", jumlahLulus);

    printf("Nilai setelah remedial: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", nilai[i]);
    }

    return 0;
}