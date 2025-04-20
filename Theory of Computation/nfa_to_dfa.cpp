#include <bits/stdc++.h>
using namespace std;
int main() {
    cout<<"sta: 0(initial), 1, 2 ... 9(max limit)\n";
    cout<<"sta -1: dead sta\n";
    cout<<"inp: 0, 1, 2 ... 9(max limit)\n";
    cout<<"first enter num of sta then the sta\n";
    int nfa_sta_num, inp, nfa_fin_cnt;
    int i,j,k,l;
    cout<<"\nsta and inp in nfa: ";
    cin>>nfa_sta_num>>inp; 
    int nfa[nfa_sta_num][inp][nfa_sta_num], nfa_len[nfa_sta_num][inp];
    cout<<"sta\tinp\n";
    for(i=0;i<nfa_sta_num;i++){
        for(j=0;j<inp;j++){
            cout<<i<<"\t"<<j<<" : ";
            cin>>nfa_len[i][j];
            for(k=0;k<nfa_len[i][j];k++) cin>>nfa[i][j][k];
        }
    }
    cout<<"num of fin sta and fin sta:\n"; 
    cin>>nfa_fin_cnt;
    int nfa_fin[nfa_fin_cnt];
    for(i=0;i<nfa_fin_cnt;i++) cin>>nfa_fin[i];
    
    for(i=-1;i<nfa_sta_num;i++){
        for(j=-1;j<inp;j++){
            if (i==-1 && j==-1){
                cout<<"\n\nnfa\t";
                continue;
            }
            if(i==-1 || j==-1){
                cout<<i+j+1;
                if(i==-1) cout<<"\t";
                continue;
            }
            cout<<"\t";
            for(k=0;k<nfa_len[i][j];k++) cout<<nfa[i][j][k];
        }
        cout<<endl;
    }
    cout<<"\nnfa fin sta:\n";
    for(i=0;i<nfa_fin_cnt;i++) cout<<nfa_fin[i]<<endl;
    
    int dfa_sta_num=pow(2,nfa_sta_num);
    int dfa_sta[dfa_sta_num][nfa_sta_num], dfa_sta_len[dfa_sta_num], dfa_sta_cnt=0;
    int dfa[dfa_sta_num][inp][nfa_sta_num], dfa_len[dfa_sta_num][inp];
    int dfa_fin[dfa_sta_num][nfa_sta_num], dfa_fin_len[dfa_sta_num], dfa_fin_cnt=0;
    int cur_sta[nfa_sta_num], cur_sta_len=1; cur_sta[0]=0;
    int p1=0, p2=-1, flag1, flag2;
    while(1){
        flag1=1;
        for (i=0;i<dfa_sta_cnt;i++){
            if (dfa_sta_len[i]==cur_sta_len){
                for(j=0;j<cur_sta_len;j++){
                    if (cur_sta[j]==dfa_sta[i][j]) flag1=0;
                    else{
                        flag1=1;
                        break;
                    }
                }
                if(!flag1) break;
            }
        }
        if(flag1){
            int out[inp][nfa_sta_num], out_len[inp]={};
            if(cur_sta_len!=1 || cur_sta[0]!=-1){
                for(i=0;i<cur_sta_len;i++){
                    for (j=0;j<inp;j++){
                        int tem_len=nfa_len[cur_sta[i]][j];
                        int tem_sta[tem_len];
                        for(k=0;k<tem_len;k++){
                            tem_sta[k]=nfa[cur_sta[i]][j][k];
                            flag2=1;
                            for(l=0;l<out_len[j];l++){
                                if (tem_sta[k]==out[j][l]){
                                    flag2=0;
                                    break;
                                }
                            }
                            if (flag2){
                                out_len[j]++;
                                out[j][l]=tem_sta[k];
                            }
                        }
                    }
                }
            }
            for(i=0;i<cur_sta_len;i++) dfa_sta[dfa_sta_cnt][i]=cur_sta[i];
            dfa_sta_len[dfa_sta_cnt]=cur_sta_len;
            for(i=0;i<inp;i++){
                if(out_len[i]==0){
                    out_len[i]=1;
                    out[i][0]=-1;
                }
                sort(out[i],out[i]+out_len[i]);
                dfa_len[dfa_sta_cnt][i]=out_len[i];
                for(j=0;j<out_len[i];j++) dfa[dfa_sta_cnt][i][j]=out[i][j];
            }
            dfa_sta_cnt++;
            flag2=0;
            for(i=0;i<nfa_fin_cnt;i++){
                for(j=0;j<cur_sta_len;j++){
                    if (nfa_fin[i]==cur_sta[j]){
                        dfa_fin_len[dfa_fin_cnt]=cur_sta_len;
                        for(k=0;k<cur_sta_len;k++) dfa_fin[dfa_fin_cnt][k]=cur_sta[k];
                        dfa_fin_cnt++;
                        flag2=1;
                        break;
                    }
                }
                if(flag2) break;
            }
        }
        if (dfa_sta_cnt*inp==(p1+1)*(p2+1) && !flag1) break;
        p2++;
        if (p2==inp){
            p2=0; p1++;
        }
        cur_sta_len=dfa_len[p1][p2];
        for(i=0;i<cur_sta_len;i++) cur_sta[i]=dfa[p1][p2][i];
    }
    for(i=-1;i<dfa_sta_cnt;i++){
        for(j=-1;j<inp;j++){
            if (i==-1 && j==-1){
                cout<<"\n\ndfa\t";
                continue;
            }
            if(i==-1){
                cout<<j<<"\t";
                continue;
            }
            if(j==-1){
                for(k=0;k<dfa_sta_len[i];k++) cout<<dfa_sta[i][k];
                continue;
            }
            cout<<"\t";
            for(k=0;k<dfa_len[i][j];k++) cout<<dfa[i][j][k];
        }
        cout<<endl;
    }
    cout<<"\ndfa fin sta:\n";
    for(i=0;i<dfa_fin_cnt;i++){
        for(j=0;j<dfa_fin_len[i];j++) cout<<dfa_fin[i][j];
        cout<<"\n";
    }
    return 0;
}