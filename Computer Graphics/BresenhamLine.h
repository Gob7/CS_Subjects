#include <bits/stdc++.h>
using namespace std;

void bresenhamLine(const int x0, const int y0, const int x1, const int y1)
{
    const int dx = x1 - x0, dy = y1 - y0;
    const int adx = abs(dx), ady = abs(dy);
    int i, step, p, x = x0, y = y0;

    if (adx >= ady)
    {
        p = 2 * ady - adx;
        p = dy < 0 ? -p : p;
        step = adx;
    }
    else
    {
        p = 2 * adx - ady;
        p = dx < 0 ? -p : p;
        step = ady;
    }

    cout << endl // << "\tp = " << p
         << x << ", " << y << endl;
    for (i = 0; i < step; i++)
    {
        if (adx >= ady && dx > 0 && dy >= 0)
        {
            if (p >= 0)
            {
                p -= 2 * dx;
                y++;
            }
            p += 2 * dy;
            x++;
        }
        else if (adx >= ady && dx > 0 && dy < 0)
        {
            if (p <= 0)
            {
                p += 2 * dx;
                y--;
            }
            p += 2 * dy;
            x++;
        }
        else if (adx >= ady && dx < 0 && dy >= 0)
        {
            if (p >= 0)
            {
                p += 2 * dx;
                y++;
            }
            p += 2 * dy;
            x--;
        }
        else if (adx >= ady && dx < 0 && dy < 0)
        {
            if (p <= 0)
            {
                p -= 2 * dx;
                y--;
            }
            p += 2 * dy;
            x--;
        }
        else if (adx < ady && dy > 0 && dx >= 0)
        {
            if (p >= 0)
            {
                p -= 2 * dy;
                x++;
            }
            p += 2 * dx;
            y++;
        }
        else if (adx < ady && dy > 0 && dx < 0)
        {
            if (p <= 0)
            {
                p += 2 * dy;
                x--;
            }
            p += 2 * dx;
            y++;
        }
        else if (adx < ady && dy < 0 && dx >= 0)
        {
            if (p >= 0)
            {
                p += 2 * dy;
                x++;
            }
            p += 2 * dx;
            y--;
        }
        else if (adx < ady && dy < 0 && dx < 0)
        {
            if (p <= 0)
            {
                p -= 2 * dy;
                x--;
            }
            p += 2 * dx;
            y--;
        }
        cout << x << ", " << y << "\tp = " << p << endl;
    }
    cout << endl;
}
