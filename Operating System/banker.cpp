#include <bits/stdc++.h>
using namespace std;
void print(int n, int m, int *arr){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            cout<<*(arr+i*m+j)<<' ';
        cout<<endl;
    }
    cout<<endl;
}
int safe(int n, int m, int *all, int *ned, int *avl){
    int sat[n] = {0}, x, y, i, j, f;
    x = accumulate(sat, sat+n, 0);
    while(1){
        for (i=0; i<n; i++){
            if (sat[i]==1) continue;
            f = 1;
            for (j=0; j<m; j++)
                if (*(ned+i*m+j)>avl[j]) f = 0;
            if (f){
                sat[i] = 1;
                for (j=0; j<m; j++){
                    avl[j] += *(all + i*m + j);
                    *(all + i*m + j) = 0;
                    *(ned + i*m + j) = 0;
                }
            }
        }
        y = accumulate(sat, sat+n, 0);
        if (x==y) break;
        x = y;
    }
    if (x==n) return 1;
    return 0;
}
int main(){
    int n, m, i, j, k, e=0, t, s;
    cout<<"Enter number of processes: "; cin>>n;
    cout<<"Enter number of resources: "; cin>>m;
    if (n<0 || m<0){
        cout<<"\nWrong input!!!"<<endl;
        exit(0);
    }
    int max[n][m], all[n][m], ned[n][m], tot[m], avl[m], AVL[m], NED[n][m], ALL[n][m];
    cout<<"\nEnter 'maximum' matrix:"<<endl; 
    for (i=0; i<n; i++){
        for (j=0; j<m; j++)
            cin>>max[i][j];
    }
    cout<<"\nEnter 'allocation' matrix:"<<endl; 
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            cin>>all[i][j];
            ned[i][j] = max[i][j] - all[i][j];
            if (ned[i][j]<0 || max[i][j]<0 || all[i][j]<0) e=1;
        }
    }
    cout<<"\nEnter 'total' matrix:"<<endl; 
    for (j=0; j<m; j++){
        cin>>tot[j];
        t = 0;
        for (i=0; i<n; i++) t += all[i][j];
        avl[j] = tot[j] - t;
        if (tot[j]<0 || avl[j]<0) e=1;
    }
    if (e){
        cout<<"\nWrong input!!!"<<endl;
        exit(0);
    }
    copy(avl, avl+m, AVL);
    for (k=0; k<n; k++){
        copy(all[k], all[k]+m, ALL[k]);
        copy(ned[k], ned[k]+m, NED[k]);
    }
    s = safe(n, m, ALL[0], NED[0], AVL);
    if (!s){
        cout<<"\nUnsafe sequence!!!"<<endl;
        exit(0);
    }
    cout<<"\nSafe sequence..."<<endl;
    cout<<"\nPress '0' to quit: "; cin>>t;
    if (!t) exit(0);
    int req[n][m];
    cout<<"\nEnter 'request' matrix:"<<endl; 
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            cin>>req[i][j];
            if (ned[i][j]<req[i][j] || avl[j]<req[i][j] || req[i][j]<0) e=1;
        }
    }
    if (e){
        cout<<"\nWrong input!!!"<<endl;
        exit(0);
    }
    for (i=0; i<n; i++){
        copy(avl, avl+m, AVL);
        for (k=0; k<n; k++){
            copy(all[k], all[k]+m, ALL[k]);
            copy(ned[k], ned[k]+m, NED[k]);
        }
        for (j=0; j<m; j++){
            AVL[j] -= req[i][j];
            NED[i][j] -= req[i][j];
            ALL[i][j] += req[i][j];
        }
        s = safe(n, m, ALL[0], NED[0], AVL);
        if (s) cout<<"Request "<<i<<" can be granted."<<endl;
        else cout<<"Can't grant request "<<i<<endl;
    }
    /*cout<<endl;
    print(n, m, max[0]);
    print(n, m, all[0]);
    print(n, m, ned[0]);
    print(1, m, tot);
    print(1, m, avl);*/
    return 0;
}