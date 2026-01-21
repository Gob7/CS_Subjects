#include <bits/stdc++.h>
using namespace std;

void digitalDifferentialAnalyzer(const int x0, const int y0, const int x1, const int y1)
{
    float x = x0, y = y0;
    const int dx = x1 - x0, dy = y1 - y0;
    const int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    if (!step)
    {
        cout << endl
             << x0 << ", " << y0 << endl;
        return;
    }

    const float xi = (float)dx / step, yi = (float)dy / step;
    cout << endl
         << round(x) << ", " << round(y) << endl;
    for (int i = 0; i < step; i++)
    {
        x += xi;
        y += yi;
        cout << round(x) << ", " << round(y) << endl;
    }
    cout << endl;
}