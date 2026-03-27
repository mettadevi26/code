#include <stdio.h>
#include <math.h>

int main() {
    float a[3], b[3];
    float sum[3], diff[3];
    float dot;
    float cross[3];
    float jarakA, jarakB, jarakCross;
    float angleRad, angleDeg;

    printf("Masukkan komponen vektor A (a1 a2 a3): ");
    scanf("%f %f %f", &a[0], &a[1], &a[2]);

    printf("Masukkan komponen vektor B (b1 b2 b3): ");
    scanf("%f %f %f", &b[0], &b[1], &b[2]);

    for (int i = 0; i < 3; i++) {
        sum[i] = a[i] + b[i];
    }

    for (int i = 0; i < 3; i++) {
        diff[i] = a[i] - b[i];
    }

    dot = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];

    cross[0] = (a[1]*b[2] - a[2]*b[1]);          
    cross[1] = -(a[0]*b[2] - a[2]*b[0]);         
    cross[2] = (a[0]*b[1] - a[1]*b[0]);          

    jarakA = sqrt(a[0]*a[0] + a[1]*a[1] + a[2]*a[2]);
    jarakB = sqrt(b[0]*b[0] + b[1]*b[1] + b[2]*b[2]);
    jarakCross = sqrt(cross[0]*cross[0] + cross[1]*cross[1] + cross[2]*cross[2]);

    if (jarakA == 0 || jarakB == 0) {
        angleDeg = 0;  
    } else {
        angleRad = acos(dot / (jarakA * jarakB));
        angleDeg = angleRad * 180.0 / M_PI;
    }


    printf("A + B = (%.2f, %.2f, %.2f)\n", sum[0], sum[1], sum[2]);
    printf("A - B = (%.2f, %.2f, %.2f)\n", diff[0], diff[1], diff[2]);
    printf("A . B = %.2f\n", dot);
    printf("A x B = (%.2f, %.2f, %.2f)\n", cross[0], cross[1], cross[2]);
    printf("||A|| = %.2f\n", jarakA);
    printf("||B|| = %.2f\n", jarakB);
    printf("||A x B|| = %.2f\n", jarakCross);
    printf("Sudut antara vektor A dan B = %.2f derajat\n", angleDeg);

    printf ("Mettadevi || 825250074");
    return 0;
}
