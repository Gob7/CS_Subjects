/*WAP to calculate simple intrest and compound intrest for given
principal amount and time period (take rate of intrest yourself).*/
#include <bits/stdc++.h>
using namespace std;
class check{
    float p,r,t,si,ci;
    public:
    void intrest(float P,float T,float R=17.5){
        p=P;
        r=R;
        t=T;
        cout<<"\nPrincipal\t: "<<p<<endl;
        cout<<"Rate of intrest\t: "<<r<<endl;
        cout<<"Time period\t: "<<t<<endl;
        si=floor(p*r*t+.5)/100;
        ci=p*(pow((1+r/100.0),floor(t))-1)+p*r*(t-floor(t))/100.0;
        ci=floor(ci*100+.5)/100;
        cout<<"Intrest:\nSimple\t\t= "<<si<<endl;
        cout<<"Compound\t= "<<ci<<endl;
    }
};
int main(){
    check c;
    c.intrest(500.75,7.5);
    c.intrest(10000,5,10);
    return 0;
}