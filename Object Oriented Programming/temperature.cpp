//WAP to convert temperature
#include <iostream>
using namespace std;
class temp{
    public:
    void cel(double a[3]);
    void far(double a[3]);
    void kel(double a[3]);
};
void temp::cel(double a[3]){
    cout<<"\nCelcius: ";
    cin>>a[0];
    a[1]=(a[0]*9/5.0)+32;
    a[2]=a[0]+273.15;
}
void temp::far(double a[3]){
    cout<<"\nFarenheit: ";
    cin>>a[1];
    a[0]=(a[1]-32)*5/9.0;
    a[2]=a[0]+273.15;
}
void temp::kel(double a[3]){
    cout<<"\nKelvin: ";
    cin>>a[2];
    a[0]=a[2]-273.15;
    a[1]=(a[0]*9/5.0)+32;
}
int main(){
    temp t;
    int x,f=1;
    double a[3];
    cout<<"\nPress\tFor\n1.\tCelcius\n2.\tFarenheit\n3.\tKelvin\n";
    cin>>x;
    switch(x){
        case 1:
        t.cel(a);
        break;
        case 2:
        t.far(a);
        break;
        case 3:
        t.kel(a);
        break;
        default:
        f=0;
        cout<<"\nWrong choice";
    }
    if (f && a[2]>=0)
    cout<<"\nCelcius \t= "<<a[0]<<"\nFarenheit \t= "<<a[1]<<"\nKelvin \t\t= "<<a[2];
    else if(f && a[2]<0)
    cout<<"Such temperature doesn't exist.";
    return 0;
}