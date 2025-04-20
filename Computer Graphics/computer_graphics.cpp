#include <bits/stdc++.h>
#include "dda_line.h"
#include "cs_line_clip.h"
#include "bresensham_line.h"
using namespace std;

int main(){
    int x_min, y_min, x_max, y_max, x0, y0, x1, y1, c;
    //cout<<"\nEnter clip window\nx_min y_min x_max y_max: ";
    //cin>>x_min>>y_min>>x_max>>y_max;
    cout<<"\nEnter end points\nx0 y0 x1 y1: ";
    cin>>x0>>y0>>x1>>y1;
    /*int X0=x0, Y0=y0, X1=x1, Y1=y1;
    clip(x_min, y_min, x_max, y_max, &x0, &y0, &x1, &y1, &c);
    if(c){
        cout<<"\nNew points:"<<endl;
        cout<<"x0 = "<<x0<<", y0 = "<<y0<<"\nx1 = "<<x1<<", y1 = "<<y1<<endl;
        c = 0;
        cout<<"\nPress 1 to draw line: ";
        cin>>c;
        if(c) dda(x0, y0, x1, y1);
    }
    else{
        cout<<"\nLine outside clipping window!"<<endl;
    }*/
    cout<<"BLD ";
    bld(x0, y0, x1, y1);
    cout<<"\nDDA ";
    dda(x0, y0, x1, y1);
    return 0;
}