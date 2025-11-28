// Digital Differential Analyzer line drawing algorithm
#include <bits/stdc++.h>
using namespace std;

void dda(int x0, int y0, int x1, int y1)
{
    cout << "\nPoints of the line are:" << endl;
    int dx = x1 - x0, dy = y1 - y0, i;
    int stp = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xi = (float)dx / stp, yi = (float)dy / stp, x = x0, y = y0;
    for (i = 0; i <= stp; i++)
    {
        cout << round(x) << ", " << round(y) << endl;
        x += xi;
        y += yi;
    }
}