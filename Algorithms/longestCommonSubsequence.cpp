#include <bits/stdc++.h>
using namespace std;
void lcs(int n1, char s1[], int n2, char s2[]){
    int res[n1+1][n2+1],i,j,k,l;
    for(i=0;i<=n1;i++){
        for(j=0;j<=n2;j++){
            if(i==0 || j==0) res[i][j]=0;
            else if(s1[i-1]==s2[j-1]) res[i][j]=res[i-1][j-1]+1;
            else res[i][j]=max(res[i][j-1],res[i-1][j]);
        }
    }
    l=res[n1][n2]; char s[l];
    i--; j--; k=l-1;
    while(k>=0){
        if(s1[i-1]==s2[j-1]){
            s[k]=s1[i-1];
            k--; i--; j--;
        }
        else if(res[i][j]==res[i-1][j]) i--;
        else j--;
    }
    cout<<"\nLongest Common Subsequence: ";
    for(k=0;k<l;k++) cout<<s[k];
    cout<<endl;
}
int main(){
    int n1,n2,i;
    cout<<"Enter length and 1st string: ";
    cin>>n1; char s1[n1];
    for (i=0;i<n1;i++) cin>>s1[i];
    cout<<"Enter length and 2nd string: ";
    cin>>n2; char s2[n2];
    for (i=0;i<n2;i++) cin>>s2[i];
    lcs(n1,s1,n2,s2);
    return 0;
}