// Time complexity, T(n) = O(2^n)
#include <stdio.h>

void toh (int n, char src, char aux, char dest){
    if (n==1){
        // base case
        printf("disk %d: %c -> %c\n", n, src, dest);
        return;
    }
    // move (n-1) items above biggest from source to auxilary using destination
    toh(n-1, src, dest, aux);
    // move the biggest item from source to destination
    printf("disk %d: %c -> %c\n", n, src, dest);
    // move all items (n-1) from auxilary to destination using source
    toh(n-1, aux, src, dest);
}

void main(){
    int n;
    printf("n = ");
    scanf("%d", &n);
    if (n<1) return;
    toh(n, 'A', 'B', 'C');
}