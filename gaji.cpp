#include <stdio.h>

// function hitung gaji
float hitungGaji(float gajiPokok, int jamLembur, float *lembur, float *pajak) {
    float tarifLembur = 20000; 

    *lembur = jamLembur * tarifLembur;

    float totalKotor = gajiPokok + *lembur;

    *pajak = 0.05 * totalKotor; 

    float totalBersih = totalKotor - *pajak;

    return totalBersih;
}

// function cetak struk
void cetakStruk(char nama[], float gajiPokok, int jamLembur,
                float lembur, float pajak, float total) {

    printf("\n===== SLIP GAJI =====\n");
    printf("Nama           : %s\n", nama);
    printf("Gaji Pokok     : %.0f\n", gajiPokok);
    printf("Lembur (%d jam): %.0f\n", jamLembur, lembur);
    printf("Pajak (5%%)     : -%.0f\n", pajak);
    printf("----------------------\n");
    printf("Gaji Bersih    : %.0f\n", total);
    printf("======================\n");
}

int main() {
    char nama[50];
    float gajiPokok, lembur, pajak, total;
    int jamLembur;

    printf("Nama karyawan: ");
    scanf(" %[^\n]", nama);

    printf("Gaji pokok: ");
    scanf("%f", &gajiPokok);

    printf("Jam lembur: ");
    scanf("%d", &jamLembur);

    total = hitungGaji(gajiPokok, jamLembur, &lembur, &pajak);

    cetakStruk(nama, gajiPokok, jamLembur, lembur, pajak, total);

    return 0;
}