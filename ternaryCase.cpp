#include <stdio.h>

int main () {
 
    int SKS, lama_semester, skripsi, tulisan_ilmiah, SKPI, sertifikasi;
    float IPK;

    printf ("Cek Kelulusan Mahasiswa Untar \n");

    printf ("Masukkan jumlah SKS anda: ");
    scanf ("%d" , &SKS);
    printf ("Masukkan jumlah IPK anda: ");
    scanf ("%f" , &IPK);
    printf ("Masukkan lama studi (semester) anda: ");
    scanf ("%d" , &lama_semester);
    printf ("Apakah skripsi anda lulus? (1 = ya, 0 = tidak) ");
    scanf ("%d" , &skripsi);
    printf ("Apakah anda sudah memiliki tulisan ilmiah? (1 = ya, 0 = tidak) ");
    scanf ("%d" , &tulisan_ilmiah);
    printf ("Masukkan jumlah poin SKPI anda: ");
    scanf ("%d" , &SKPI);
    printf ("Apakah anda sudah memiliki sertifikasi UNTAR? (1 = ya, 0 = tidak) ");
    scanf ("%d" , &sertifikasi);

    int lulus = (SKS >= 144) && (IPK >= 2.4) && (lama_semester <= 16) && (skripsi = 1) && (tulisan_ilmiah = 1) && (SKPI >= 150) && (sertifikasi = 1);

    lulus ? printf ("Selamat! Anda dinyatakan lulus. \n") : printf ("Maaf, Anda dinyatakan tidak lulus karena: \n");

    //alasan ketidaklulusannya
    (SKS >= 144) ? 0 : printf ("SKS anda kurang dari 144. \n");
    (IPK >= 2.4) ? 0 : printf ("IPK anda kurang dari 2.4. \n");
    (lama_semester <= 16) ? : printf ("Lama studi anda lebih dari 16 semester. \n");
    (skripsi == 1) ? 0 : printf ("Anda tidak lulus skripsi. \n");
    (tulisan_ilmiah == 1) ? 0 : printf ("Anda belum memiliki tulisan ilmiah. \n");
    (SKPI >= 150) ? 0 : printf ("Jumlah poin anda kurang dari 150. \n");
    (sertifikasi == 1) ? 0 : printf ("Anda belum memiliki sertifikasi UNTAR. \n");

    return 0;

}
