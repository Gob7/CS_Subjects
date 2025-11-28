// Converting temperature
// temperature[3] -> 0: celsius, 1: fahrenheit, 2: kelvin
#include <bits/stdc++.h>
using namespace std;

class convertTemperature
{
public:
    void celsius(double temperature[3]);
    void fahrenheit(double temperature[3]);
    void kelvin(double temperature[3]);
};

void convertTemperature::celsius(double temperature[3])
{
    cout << "\nCelsius: ";
    cin >> temperature[0];
    temperature[1] = (temperature[0] * 9 / 5.0) + 32;
    temperature[2] = temperature[0] + 273.15;
}

void convertTemperature::fahrenheit(double temperature[3])
{
    cout << "\nFahrenheit: ";
    cin >> temperature[1];
    temperature[0] = (temperature[1] - 32) * 5 / 9.0;
    temperature[2] = temperature[0] + 273.15;
}

void convertTemperature::kelvin(double temperature[3])
{
    cout << "\nKelvin: ";
    cin >> temperature[2];
    temperature[0] = temperature[2] - 273.15;
    temperature[1] = (temperature[0] * 9 / 5.0) + 32;
}

int main()
{
    convertTemperature x;
    int choice, flag = 1;
    double temperature[3];

    cout << "\nPress\tFor\n1.\tCelsius\n2.\tFahrenheit\n3.\tKelvin\n\nPressed : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        x.celsius(temperature);
        break;
    case 2:
        x.fahrenheit(temperature);
        break;
    case 3:
        x.kelvin(temperature);
        break;
    default:
        flag = 0;
        cout << "\nWrong choice.";
    }

    if (flag && temperature[2] >= 0)
        cout << "\nCelsius\t\t=\t" << temperature[0]
             << "\nFahrenheit\t=\t" << temperature[1]
             << "\nKelvin\t\t=\t" << temperature[2];

    else if (flag && temperature[2] < 0)
        cout << "Such temperature doesn't exist.";

    return 0;
}