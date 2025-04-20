// Matrix multiplication
#include <bits/stdc++.h>
using namespace std;

// Classical Method
void matrixMulBF(int *a, int *b, int *c, int row, int mid, int col){
    int i, j, k;
    for (i=0; i<row; i++){
        for (k=0; k<col; k++){
            c[i*col + k] = 0;
            // cout<<"c["<<i<<","<<k<<"] = ";
            for (j=0; j<mid; j++){
                // cout<<"a["<<i<<","<<j<<"]*b["<<j<<","<<k<<"] + ";
                c[i*col + k] += a[i*mid + j] * b[j*col + k];
            }
        }
    }
}

void matrixDivide(int *a, int *b, int *a0, int *a1, int *a2, int *a3, int *b0, int *b1, int *b2, int *b3, int n){
    int i, j, m = n/2;

    for (i=0; i<m; i++){
        for (j=0; j<m; j++){
            a0[i*m + j] = a[i*n + j];
            b0[i*m + j] = b[i*n + j];
        }
        for (; j<n; j++){
            a1[i*m + j-m] = a[i*n + j];
            b1[i*m + j-m] = b[i*n + j];
        }
    }
    for (; i<n; i++){
        for (j=0; j<m; j++){
            a2[(i-m)*m + j] = a[i*n + j];
            b2[(i-m)*m + j] = b[i*n + j];
        }
        for (; j<n; j++){
            a3[(i-m)*m + j-m] = a[i*n + j];
            b3[(i-m)*m + j-m] = b[i*n + j];
        }
    }
}
void matrixCombine(int *c, int *c0, int *c1, int *c2, int *c3, int n){
    int i, j, m = n/2;

    for (i=0; i<m; i++){
        for (j=0; j<m; j++)
            c[i*n + j] = c0[i*m + j];
        for (; j<n; j++)
            c[i*n + j] = c1[i*m + j-m];
    }
    for (; i<n; i++){
        for (j=0; j<m; j++)
            c[i*n + j] = c2[(i-m)*m + j];
        for (; j<n; j++)
            c[i*n + j] = c3[(i-m)*m + j-m];
    }
}

// Divide & conquer method
void matrixMulDC(int *a, int *b, int *c, int n){
    if (n == 1){
        c[0] = a[0] * b[0];
        return;
    }
    int m = n/2, i, j;
    int c0[m][m], c1[m][m], c2[m][m], c3[m][m], c4[m][m], c5[m][m], c6[m][m], c7[m][m];
    int a0[m][m], a1[m][m], a2[m][m], a3[m][m];
    int b0[m][m], b1[m][m], b2[m][m], b3[m][m];
    matrixDivide(a, b, a0[0], a1[0], a2[0], a3[0], b0[0], b1[0], b2[0], b3[0], n);

    // 8 Multiplications & 4 Additions
    matrixMulDC(a0[0], b0[0], c0[0], m);
    matrixMulDC(a1[0], b2[0], c1[0], m);
    matrixMulDC(a0[0], b1[0], c2[0], m);
    matrixMulDC(a1[0], b3[0], c3[0], m);
    matrixMulDC(a2[0], b0[0], c4[0], m);
    matrixMulDC(a3[0], b2[0], c5[0], m);
    matrixMulDC(a2[0], b1[0], c6[0], m);
    matrixMulDC(a3[0], b3[0], c7[0], m);
    
    matrixAdd(c0[0], c1[0], c0[0], m, m);
    matrixAdd(c2[0], c3[0], c2[0], m, m);
    matrixAdd(c4[0], c5[0], c4[0], m, m);
    matrixAdd(c6[0], c7[0], c6[0], m, m);
    matrixCombine(c, c0[0], c2[0], c4[0], c6[0], n);
}

// Strassen's method
void strassen(int *a, int *b, int *c, int n){
    if (n == 1){
        c[0] = a[0] * b[0];
        return;
    }
    int m = n/2, i, j;
    int c0[m][m], c1[m][m], c2[m][m], c3[m][m], c4[m][m], c5[m][m], c6[m][m];
    int a0[m][m], a1[m][m], a2[m][m], a3[m][m];
    int b0[m][m], b1[m][m], b2[m][m], b3[m][m];
    int x0[m][m], x1[m][m];
    matrixDivide(a, b, a0[0], a1[0], a2[0], a3[0], b0[0], b1[0], b2[0], b3[0], n);

    // 7 Multiplications & 18 Additions
    matrixAdd(a0[0], a3[0], x0[0], m, m);
    matrixAdd(b0[0], b3[0], x1[0], m, m);
    strassen(x0[0], x1[0], c0[0], m);
    // cout<<"P1 =\n"; matrixPrint(c0[0], m, m);
    matrixAdd(a2[0], a3[0], x0[0], m, m);
    strassen(x0[0], b0[0], c1[0], m);
    // cout<<"P2 =\n"; matrixPrint(c1[0], m, m);
    matrixSub(b1[0], b3[0], x0[0], m, m);
    strassen(a0[0], x0[0], c2[0], m);
    // cout<<"P3 =\n"; matrixPrint(c2[0], m, m);
    matrixSub(b2[0], b0[0], x0[0], m, m);
    strassen(a3[0], x0[0], c3[0], m);
    // cout<<"P4 =\n"; matrixPrint(c3[0], m, m);
    matrixAdd(a0[0], a1[0], x0[0], m, m);
    strassen(x0[0], b3[0], c4[0], m);
    // cout<<"P5 =\n"; matrixPrint(c4[0], m, m);
    matrixSub(a2[0], a0[0], x0[0], m, m);
    matrixAdd(b0[0], b1[0], x1[0], m, m);
    strassen(x0[0], x1[0], c5[0], m);
    // cout<<"P6 =\n"; matrixPrint(c5[0], m, m);
    matrixSub(a1[0], a3[0], x0[0], m, m);
    matrixAdd(b2[0], b3[0], x1[0], m, m);
    strassen(x0[0], x1[0], c6[0], m);
    // cout<<"P7 =\n"; matrixPrint(c6[0], m, m);

    matrixAdd(c0[0], c6[0], c6[0], m, m);
    matrixAdd(c3[0], c6[0], c6[0], m, m);
    matrixSub(c6[0], c4[0], c6[0], m, m);
    // cout<<"c6 =\n"; matrixPrint(c6[0], m, m);
    matrixAdd(c2[0], c4[0], c4[0], m, m);
    // cout<<"c4 =\n"; matrixPrint(c4[0], m, m);
    matrixAdd(c1[0], c3[0], c3[0], m, m);
    // cout<<"c3 =\n"; matrixPrint(c3[0], m, m);
    matrixAdd(c0[0], c5[0], c5[0], m, m);
    matrixAdd(c2[0], c5[0], c5[0], m, m);
    matrixSub(c5[0], c1[0], c5[0], m, m);
    // cout<<"c5 =\n"; matrixPrint(c5[0], m, m);
    matrixCombine(c, c6[0], c4[0], c3[0], c5[0], n);
}