#include <bits/stdc++.h>
using namespace std;

// Classical Method
vector <int> longIntMulBF(vector <int> a, vector <int> b){
    a = trimmer(a);
    b = trimmer(b);
    int i, j, s, car;
    vector <int> arr[b.size()], c;

    for (i=0; i<b.size(); i++){
        car = 0;
        for (j=0; j<a.size(); j++){
            s = b[i]*a[j] + car;
            arr[i].push_back(s%10);
            car = s/10;
        }
        arr[i] = pushIntToVec(arr[i], car);
        arr[i] = trimmer(arr[i]);

        // cout<<"\narr["<<i<<"] = ";
        // numPrint(arr[i]);
    }

    c = arr[0];
    for (i=1; i<b.size(); i++){
        if (arr[i].size() == 1 && !arr[i][0])
            continue;
        arr[i] = pushZero(arr[i], i);
        c = longIntAdd(c, arr[i]);
    }
    return c;
}


void longIntDivide(vector <int> a, vector <int> b, int m1, int m2, vector <int> &w, vector <int> &x, vector <int> &y, vector <int> &z){
    for (int i=0; i<a.size(); i++){
        if (i<m1)
            x.push_back(a[i]);
        else
            w.push_back(a[i]);
    }
    if (a.size() == 1)
        w.push_back(0);

    for (int i=0; i<b.size(); i++){
        if (i<m2)
            z.push_back(b[i]);
        else
            y.push_back(b[i]);
    }
    if (m2 == b.size())
        y.push_back(0);
}
void longIntDivideNew(vector <int> a, vector <int> b, int m, vector <int> &w, vector <int> &x, vector <int> &y, vector <int> &z){
    int i=0;
    for (; i<m; i++){
        x.push_back(a[i]);
        z.push_back(b[i]);  
    }
    for (; i<a.size(); i++){
        w.push_back(a[i]);
        y.push_back(b[i]);
    }
}

// Divide & Conquer
vector <int> longIntMulDC(vector <int> a, vector <int> b){
    a = trimmer(a);
    b = trimmer(b);
    vector <int> c, w, x, y, z, p, q, r;
    int m1, m2, i;

    if (a.size() == 1 && b.size() == 1){
        c = intToVec(a[0]*b[0]);
        return c;
    }

    // a = w * 10^m1 + x
    // b = y * 10^m2 + z 
    m1 = a.size()==1 ? 1 : a.size()/2;
    m2 = b.size()>m1 ? m1 : b.size();
    longIntDivide(a, b, m1, m2, w, x, y, z);

    // 4 Multiplications & 3 Additions
    p = longIntMulDC(w, y);
    q = longIntMulDC(w, z);
    r = longIntMulDC(x, y);
    c = longIntMulDC(x, z);
    
    p = pushZero(p, m1+m2);
    q = pushZero(q, m1);
    r = pushZero(r, m2);
    c = longIntAdd(c, p);
    c = longIntAdd(c, q);
    c = longIntAdd(c, r);
    return c;
}

// AK Optimization
// size(a) = size(b) = power of 2
vector <int> longIntMulAK(vector <int> a, vector <int> b){
    vector <int> c, w, x, y, z, p, q, r, s;
    int i, m = a.size()/2;
    cout<<"\n\na = "; numPrint(a);
    cout<<"\nb = "; numPrint(b);

    if (a.size() == 1 || b.size() == 1)
        return longIntMulBF(a, b);

    // FIXME: at intermediate results, length of (w,x,y,z) are not in power of 2
    longIntDivideNew(a, b, m, w, x, y, z);
    cout<<"\n\nw = "; numPrint(w);
    cout<<"\nx = "; numPrint(x);
    cout<<"\ny = "; numPrint(y);
    cout<<"\nz = "; numPrint(z);

    // 3 Multiplications & 6 Additions
    p = longIntMulAK(w, y);
    q = longIntMulAK(x, z);
    r = longIntAdd(w, x);
    s = longIntAdd(y, z);
    r = longIntMulAK(r, s);
    s = longIntAdd(p, q);
    c = longIntSub(r, s);
    cout<<"\n\np = "; numPrint(p);
    cout<<"\nq = "; numPrint(q);
    cout<<"\nr = "; numPrint(r);
    cout<<"\ns = "; numPrint(s);
    p = pushZero(p, 2*m);
    // TODO: if you change above to accept different length (w,x,y,z); can't push 'm' zeroes to 'c'
    c = pushZero(c, m);
    c = longIntAdd(c, p);
    c = longIntAdd(c, q);

    cout<<"\n\nc = "; numPrint(c);
    return c;
}