// Conversion of decimal numbers to binary using recursion
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n) {
    if (n < 2){
        printf("%d", n);
        return;
    }
    decimalToBinary(n / 2);
    printf("%d", n % 2);
}

void main(){
    int n;
    printf("Decimal = ");
    scanf("%d", &n);

    if (n<0){
        printf("Enter a whole number\n");
        exit(0);
    }
    printf("Binary : ");
    decimalToBinary(n);
    printf("\n");
}