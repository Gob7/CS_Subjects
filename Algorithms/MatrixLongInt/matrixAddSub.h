// Matrix addition & subtraction
#include <bits/stdc++.h>
using namespace std;

void matrixAdd(int *a, int *b, int *c, int row, int col){
    int i, j;
    for (i=0; i<row; i++)
        for (j=0; j<col; j++)
            c[i*col + j] = a[i*col + j] + b[i*col + j];
}

void matrixSub(int *a, int *b, int *c, int row, int col){
    int i, j;
    for (i=0; i<row; i++)
        for (j=0; j<col; j++)
            c[i*col + j] = a[i*col + j] - b[i*col + j];
}