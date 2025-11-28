// Calculate simple interest and compound interest
#include <bits/stdc++.h>
using namespace std;

class interestCalculator
{
    float principal, rate, time, simple, compound;

public:
    void findInterest(float principalAmount, float timePeriod, float rateOfInterest = 17.5)
    {
        principal = principalAmount;
        rate = rateOfInterest;
        time = timePeriod;

        cout << "\nPrincipal amount\t:\t" << principal << endl;
        cout << "Rate of interest\t:\t" << rate << endl;
        cout << "Time period\t\t:\t" << time << endl;

        simple = round(principal * rate * time) / 100;
        int t = floor(time);
        float c = principal * (pow((1 + rate / 100.0), t) - 1);
        float s = principal * rate * (time - t) / 100.0;
        compound = round((c + s) * 100) / 100;

        cout << "\nSimple interest\t\t=\t" << simple << endl;
        cout << "Compound interest\t=\t" << compound << "\n\n";
    }
};

int main()
{
    interestCalculator x;
    x.findInterest(100, 4, 10);
    x.findInterest(500.75, 7.5);
    x.findInterest(10000, 5, 10);

    return 0;
}