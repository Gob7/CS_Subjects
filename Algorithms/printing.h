#include <bits/stdc++.h>
using namespace std;

template <typename T>
void arrPrint(T *arr, int start, int end){
    for (int i=start; i<end; i++)
        cout<<"("<<arr[i]<<") -> ";
    cout<<"NULL"<<endl;
}

void vecPrint(vector <int> vec){
    for (int i=0; i<vec.size(); i++)
        cout<<"("<<vec[i]<<") -> ";
    cout<<"NULL"<<endl;
}

template <typename T>
void matrixPrint(T *a, int row, int col){
    int i, j, k=(col+1)*8+1;
    // cout<<"a["<<i<<"]["<<j<<"] = "<<endl;

    for (i=0; i<k; i++)
        cout<<"-";
    cout<<endl;

    for (i=0; i<row; i++){
        cout<<"|\t";
        for (j=0; j<col; j++)
            cout<<a[i*col+j]<<"\t";
        cout<<"|\n";
    }
    for (i=0; i<k; i++)
        cout<<"-";
    cout<<"\n\n";
}

void numPrint(vector <int> vec){
    for (int i=vec.size()-1; i>=0; i--)
        cout<<vec[i];
}
