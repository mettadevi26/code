#include <stdio.h>
#include <unistd.h> // untuk sleep()

int main() {
    int state = 0; // 0=Merah, 1=Hijau, 2=Kuning

    while (1) {
        switch (state) {
            case 0:
                printf("MERAH - Berhenti!\n");
                sleep(5); // 5 detik
                state = 1;
                break;

            case 1:
                printf("HIJAU - Jalan!\n");
                sleep(5);
                state = 2;
                break;

            case 2:
                printf("KUNING - Hati-hati!\n");
                sleep(2);
                state = 0;
                break;
        }
    }

    return 0;
}