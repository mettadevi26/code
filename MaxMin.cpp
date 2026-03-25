#include <stdio.h>
#include <stdlib.h>

void cariMinMax(int *arr, int n, int *min, int *max) {
    *min = *arr;
    *max = *arr;

    for(int i = 1; i < n; i++) {
        if(*(arr + i) < *min) *min = *(arr + i);
        if(*(arr + i) > *max) *max = *(arr + i);
    }
}

int main() {
    int n;
    printf("Jumlah data: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        printf("Input ke-%d: ", i);
        scanf("%d", &arr[i]);
    }

    int min, max;
    cariMinMax(arr, n, &min, &max);

    printf("Min: %d\n", min);
    printf("Max: %d\n", max);

    free(arr);
    return 0;
}