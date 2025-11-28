// Bresensham Line Drawing Algorithm
#include <bits/stdc++.h>
using namespace std;

void bld(int x0, int y0, int x1, int y1)
{
    cout << "\nPoints of the line are:" << endl;
    int dx = x1 - x0, dy = y1 - y0, i, stp, p;
    int adx = abs(dx), ady = abs(dy);
    if (adx >= ady)
    {
        p = 2 * dy - dx;
        stp = adx;
    }
    else
    {
        p = 2 * dx - dy;
        stp = ady;
    }
    for (i = 0; i <= stp; i++)
    {
        cout << x0 << ", " << y0 << endl;
        if (adx >= ady)
        {
            if (dx > 0 && dy >= 0)
            {
                if (p > 0)
                {
                    p -= 2 * dx;
                    y0++;
                }
                p += 2 * dy;
                x0++;
            }
            else if (dx > 0 && dy <= 0)
            {
                if (p > 0)
                {
                    p -= 2 * dx;
                    y0--;
                }
                p -= 2 * dy;
                x0++;
            }
            else if (dx < 0 && dy >= 0)
            {
                if (p < 0)
                {
                    p -= 2 * dx;
                    y0++;
                }
                p -= 2 * dy;
                x0--;
            }
            else if (dx < 0 && dy <= 0)
            {
                if (p < 0)
                {
                    p -= 2 * dx;
                    y0--;
                }
                p += 2 * dy;
                x0--;
            }
        }
        else
        {
            if (dy > 0 && dx >= 0)
            {
                if (p > 0)
                {
                    p -= 2 * dy;
                    x0++;
                }
                p += 2 * dx;
                y0++;
            }
            else if (dy > 0 && dx <= 0)
            {
                if (p > 0)
                {
                    p -= 2 * dy;
                    x0--;
                }
                p -= 2 * dx;
                y0++;
            }
            else if (dy < 0 && dx >= 0)
            {
                if (p < 0)
                {
                    p -= 2 * dy;
                    x0++;
                }
                p -= 2 * dx;
                y0--;
            }
            else if (dy < 0 && dx <= 0)
            {
                if (p < 0)
                {
                    p -= 2 * dy;
                    x0--;
                }
                p += 2 * dx;
                y0--;
            }
        }
    }
}