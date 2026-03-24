#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int secret_number, tebakkan, percobaan = 0;

    srand(time(0)); //buat bikin jawabannya random, kalo bawaaan automatically 2
    secret_number = rand() % 10 + 1; // pake + 1 supaya angkanya 1 - 10, karena int itu 10 digit yg dimulai dari 0 
    
    printf ("Game Tebak Angka (1-10) \n");

    do {
        printf ("Tebak angka dari angka 1 sampai 10 : ");
        scanf ("%d" , &tebakkan);
        percobaan ++;
        
        if (tebakkan > secret_number) {
            printf ("Angka terlalu besar \n");
        } 
            else if (tebakkan < secret_number) {
                printf ("Angka terlalu kecil \n");
            }
                else {
                    printf ("Angka Benar! \n");
                }
    } 
    while (tebakkan != secret_number);

    printf ("Tebakkan Anda Benar! Angkanya adalah %d \n" , secret_number);
    printf ("Total percobaan Anda: %d \n" , percobaan);

    return 0;

}