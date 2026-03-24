#include <stdio.h>

int main () {
    float total_pendapatan, transportasi, investasi, cicilan, kebutuhan_pokok, hiburan;

    printf ("Pembagian atau Budgeting Pendapatan Bulanan \n" );

    printf ("Masukkan total pendapatan selama sebulan = Rp ");
    scanf ("%f", &total_pendapatan);

    transportasi = total_pendapatan * 0.1;
    investasi = total_pendapatan * 0.4;
    kebutuhan_pokok = total_pendapatan * 0.35;
    hiburan = total_pendapatan * 0.15;

    printf ("Untuk biaya transportasi = Rp %.2f\n" , transportasi);
    printf ("Untuk diinvestasikan = Rp %.2f\n" , investasi);
    printf ("Untuk kebutuhan pokok = Rp %.2f\n" , kebutuhan_pokok);
    printf ("Untuk hiburan = Rp %.2f\n" , hiburan);

    return 0;
    
}