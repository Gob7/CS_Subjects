#include <bits/stdc++.h>
using namespace std;
int mcm(int a[], int i, int j){
    if (i==j) return 0;
    int k,c,m=INT_MAX;
    for (k=i;k<j;k++){
        c=mcm(a,i,k)+mcm(a,k+1,j)+a[i-1]*a[k]*a[j];
        m=min(m,c);
    }
    return m;
}
int MCM(int a[], int n){
    int res[n][n],ind[n][n];
    int p=n,q=0,r=0,i,j,k,l,m,M;
    for (i=0;i<n*(n+1)/2;i++){
        while(1){
            j=i-q;
            k=i-q+r;
            if (i<p) break;
            r++; q=p;
            p=n*(r+1)-r*(r+1)/2;
        }
        if (j==k){
            res[j][k]=0;
            ind[j][k]=0;
        }
        else{
            m=INT_MAX;
            for(l=j;l<k;l++){
                M=res[j][l]+res[l+1][k]+a[j]*a[l+1]*a[k+1];
                m=min(m,M);
            }
            res[j][k]=m;
            ind[j][k]=l;
        }
    }
    /*
    cout<<"\nres = "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) cout<<res[i][j]<<" ";
        cout<<endl;
    }
    cout<<"\nind = "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) cout<<ind[i][j]<<" ";
        cout<<endl;
    }
    */
    return res[0][n-1];
}
int main(){
    int n,i,m;
    cout<<"Number of matrices: "; 
    cin>>n; int a[n+1];
    cout<<"Dimension: "; 
    for (i=0;i<=n;i++) cin>>a[i];
    //m=mcm(a,1,n);
    m=MCM(a,n);
    cout<<"Minimum multiplication = "<<m<<endl;
    return 0;
}