// Matrix Operations
#include <bits/stdc++.h>
using namespace std;

#include "../printing.h"
#include "matrixAddSub.h"
#include "matrixMultiply.h"

int main()
{
    int row1, col1, row2, col2, n;
    // row1 = 2;
    // col1 = row2 = 4;
    // col2 = 3;

    // int a[row1][col1] = {
    //                         {1, -2, 3, 4},
    //                         {-4, 5, 6, -7}
    //                     };
    // int b[row1][col1] = {
    //                         {7, 8, 9, -3},
    //                         {0, -1, 2, -9}
    //                     };
    // int c[row1][col1];
    // int d[row2][col2] = {
    //                         {-2, 5, 8},
    //                         {-7, 4, 1},
    //                         {3, -6, 9},
    //                         {7, 0, -3}
    //                     };
    // int e[row1][col2];

    n = 2;
    int f[n][n] = {
        {5, 3},
        {1, 6}};
    int g[n][n] = {
        {8, -8},
        {-8, 5}};
    // int f[n][n] = {
    //                 {2,1,5,3},
    //                 {6,7,1,6},
    //                 {9,2,4,4},
    //                 {3,6,7,2}
    //             };
    // int g[n][n] = {
    //                 {6,1,2,3},
    //                 {4,5,6,5},
    //                 {1,9,8,-8},
    //                 {4,0,-8,5}
    //             };
    // int f[n][n] = {
    //                 {1, 2, 3, 0, 0, -4, -1, -7},
    //                 {0, 4, 1, 7, -5, 0, -2, -3},
    //                 {5, 0, 2, 3, -6, -9, 0, -8},
    //                 {6, 9, 0, 8, -1, -2, -3, 0},
    //                 {-8, -3, -2, 0, 0, 4, 1, 5},
    //                 {-1, 0, -2, -7, 8, 3, 2, 0},
    //                 {-9, -3, 0, -6, 1, 0, 2, 7},
    //                 {0, -4, -1, -5, 9, 3, 0, 6}
    //             };
    // int g[n][n] = {
    //                 {-8, -3, -2, 0, 0, 4, 1, 5},
    //                 {-1, 0, -2, -7, 8, 3, 2, 0},
    //                 {-9, -3, 0, -6, 1, 0, 2, 7},
    //                 {0, -4, -1, -5, 9, 3, 0, 6},
    //                 {1, 2, 3, 0, 0, -4, -1, -7},
    //                 {0, 4, 1, 7, -5, 0, -2, -3},
    //                 {5, 0, 2, 3, -6, -9, 0, -8},
    //                 {6, 9, 0, 8, -1, -2, -3, 0}
    //             };
    int h[n][n];

    cout << "f =\n";
    matrixPrint(f[0], n, n);
    cout << "g =\n";
    matrixPrint(g[0], n, n);

    // matrixAdd(a[0], b[0], c[0], row1, col1);
    // cout<<"a + b =\n";
    // matrixPrint(c[0], row1, col1);

    // matrixSub(a[0], b[0], c[0], row1, col1);
    // cout<<"a - b =\n";
    // matrixPrint(c[0], row1, col1);

    // matrixMulBF(a[0], d[0], e[0], row1, col1, col2);
    // cout<<"a * d =\n";
    // matrixPrint(e[0], row1, col2);

    // matrixMulBF(f[0], g[0], h[0], n, n, n);
    // cout<<"Classical\nf * g =\n";
    // matrixPrint(h[0], n, n);

    // f,g,h -> n*n matrix; n is power of 2
    // matrixMulDC(f[0], g[0], h[0], n);
    // cout<<"Divide & Conquer\nf * g =\n";
    // matrixPrint(h[0], n, n);

    // f,g,h -> n*n matrix; n is power of 2
    strassen(f[0], g[0], h[0], n);
    cout << "Strassen\nf * g =\n";
    matrixPrint(h[0], n, n);

    return 0;
}