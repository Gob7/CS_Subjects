#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
void main(){
    printf("Hello World\n");
    int x=abs(-6);
    float a=2.9, b=-3.1;
    int y=round(a), z=roundf(b);
    printf("x=%d\ny=%d\nz=%d\n",x,y,z);
    // bool a = true;
    if (true) printf("%d", NULL==NULL);
}