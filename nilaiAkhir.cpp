#include <stdio.h>

// fungsi hitung nilai akhir
float HitungNilaiAkhir (float Tugas, float UTS, float UAS) {
    return 0.3 * Tugas + 0.3 * UTS + 0.4 * UAS;
}

// fungsi remedial
float HitungRemedial (float NilaiAkhir) {
    float remedial;
    printf ("Anda tidak lulus. Silakan mengikuti remedial\n");
    printf ("Masukkan nilai remedial anda: ");
    scanf ("%f" , &remedial);

    if (remedial > NilaiAkhir) {
        NilaiAkhir = remedial;
    }
    return NilaiAkhir;
}

// fungsi grade
char tentukanGrade (float NilaiAkhir) {
    if (NilaiAkhir >= 80) {
            printf ("Anda Lulus dengan Predikat A\n");
            return 'A'; } 
        
        else if (NilaiAkhir >= 70 && NilaiAkhir <= 79) {
            printf ("Anda Lulus dengan Predikat B\n");
            return 'B' ; }

            else if (NilaiAkhir >= 60 && NilaiAkhir <= 69) {
                printf ("Anda Lulus dengan Predikat C\n");
                return 'C'; }

                else {
                    printf ("Anda Tidak Lulus. Predikat anda D\n");
                    return 'D';
                }    
}


//fungsi main
int main () {
    float Tugas, UTS, UAS, NilaiAkhir;
    int n, sumA = 0, sumB = 0, sumC = 0, sumD = 0;
    float nilaiTerendah = 100, nilaiTertinggi = 0, totalNilai = 0;
    char grade;

    printf ("Masukkan jumlah mahasiswa (maksimal 10) = ");
    scanf ("%d", &n);

    if (n <= 0 || n > 10) {
        printf ("Jumlah mahasiswa tidak valid\n");
        return 0; 
    }

    for (int i = 1; i <=n; i++) {
        printf ("\nMahasiswa ke-%d \n", i);
        printf ("Masukkan nilai Tugas, UTS, UAS = "); 
        scanf ("%f %f %f", &Tugas, &UTS, &UAS);
    
        NilaiAkhir = HitungNilaiAkhir (Tugas, UTS, UAS);

        if (NilaiAkhir < 60) {
            NilaiAkhir = HitungRemedial (NilaiAkhir);
        }

        totalNilai += NilaiAkhir;

        if (NilaiAkhir > nilaiTertinggi) {
            nilaiTertinggi = NilaiAkhir;
        }

        if (NilaiAkhir < nilaiTerendah) {
            nilaiTerendah = NilaiAkhir;
        }

        grade = tentukanGrade (NilaiAkhir);

        if (grade == 'A') sumA++;
        else if (grade == 'B') sumB++;
        else if (grade == 'C') sumC++;
        else sumD++;
        
    }

    float ratarata = totalNilai / n;

    printf("\n=== REKAP KELAS ===\n");
    printf("Rata-rata nilai akhir kelas: %.2f\n", ratarata);
    printf("Jumlah mahasiswa yang memperoleh predikat A: %d\n", sumA);
    printf("Jumlah mahasiswa yang memperoleh predikat B: %d\n", sumB);
    printf("Jumlah mahasiswa yang memperoleh predikat C: %d\n", sumC);
    printf("Jumlah mahasiswa yang memperoleh predikat D: %d\n", sumD);
    printf("Nilai tertinggi: %.2f\n", nilaiTertinggi);
    printf("Nilai terendah: %.2f\n", nilaiTerendah);
    return 0;
}