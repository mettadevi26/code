#include <stdio.h>

int main () {
    int score;

    printf ("score = ");
    scanf ("%d" , &score);
    
    if (score >= 90) {
        printf ("Grade : A \n");
    }
    else if (score >= 80) {
        printf ("Grade : B \n");
    }
    else if (score >= 70) {
        printf ("Grade : C \n");
    }
    else {
        printf ("Grade : F \n");
    }

    return 0;
}