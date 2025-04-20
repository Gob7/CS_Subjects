#include <bits/stdc++.h>
#include "printing.h"
#include "vectorOpn.h"
#include "longIntAddSub.h"
#include "longIntMul.h"
using namespace std;

int main(){
    vector <int> a, b, c, d, e, f, g, h;
    // a = {0,9,4,2,1,7};
    // b = {6,0,5,3,8,0,0};
    a = {0,9,4,7};
    b = {2,1,3,6};
    // c = longIntAdd(a, b);
    d = longIntSub(a, b);
    e = longIntMulBF(a, b);
    f = longIntMulDC(a, b);
    // FIXME:
    // g = longIntMulAK(a, b); 

    cout<<endl;
    numPrint(a);
    cout<<" * ";
    numPrint(b);
    cout<<" =\nBF: ";
    numPrint(e);
    cout<<"\nDC: ";
    numPrint(f);
    // cout<<"\nAK: ";
    // numPrint(g);

    return 0;
}