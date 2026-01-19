#include <bits/stdc++.h>
using namespace std;

#include "DigitalDifferentialAnalyzer.h"
#include "BresenhamLine.h"
#include "CohenSutherlandClip.h"

int main()
{
    int X0, Y0, X1, Y1;
    cout << "\nEnter end points\nx0 y0 x1 y1: ";
    cin >> X0 >> Y0 >> X1 >> Y1;
    const int x0 = X0, x1 = X1, y0 = Y0, y1 = Y1;

    cout << "\nPoints of the DDA Line are:";
    digitalDifferentialAnalyzer(x0, y0, x1, y1);
    cout << "Points of the Bresenham Line are:";
    bresenhamLine(x0, y0, x1, y1);
    /*
    int x_min, y_min, x_max, y_max, flag;
    cout << "\nEnter clip window\nx_min y_min x_max y_max: ";
    cin >> x_min >> y_min >> x_max >> y_max;

    flag = cohenSutherlandClip(x_min, y_min, x_max, y_max, &X0, &Y0, &X1, &Y1);
    if (flag)
    {
        cout << "\nNew points:" << endl
             << "x0 = " << X0 << ", y0 = " << Y0 << "\nx1 = " << X1 << ", y1 = " << Y1 << endl
             << endl
             << "Drawing the line...";
        bresenhamLine(X0, Y0, X1, Y1);
    }
    else
        cout << "\nLine completely outside clipping window!" << endl;
    */
    return 0;
}