#include <stdio.h>

int main() {

    int hours, minutes;
    printf("Enter the time (HH:MM):");
    scanf("%d:%d",&hours,&minutes);
    printf("The time is %d hours and %d minutes. \n",hours,minutes);

    return 0;
} 