#include <bits/stdc++.h>
using namespace std;

// Long Integer Addition
vector <int> longIntAdd(vector <int> a, vector <int> b){
    a = trimmer(a);
    b = trimmer(b);
    vector <int> c;
    int i, car, n, s;
    car = 0;
    n = max(a.size(), b.size());

    for (i=0; i<n; i++){
        s = 0;
        if (i<a.size())
            s += a[i];
        if (i<b.size())
            s += b[i];
        s += car;
        car = s/10;
        c.push_back(s%10);
    }
    c = pushIntToVec(c, car);
    return c;
}

// Long Integer Subtraction
// Assuming a>=b
vector <int> longIntSub(vector <int> a, vector <int> b){
    a = trimmer(a);
    b = trimmer(b);
    vector <int> c;
    int i, car, s;
    car = 0;

    for (i=0; i<a.size(); i++){
        s = a[i];
        if (car){
            if (s){
                s--;
                car = 0;
            }
            else
                s = 9;
        }
        if (i<b.size()){
            if (b[i]>s){
                s += 10;
                car = 1;
            }
            s -= b[i];
        }
        c.push_back(s);
    }
    c = trimmer(c);
    return c;
}