#include <bits/stdc++.h>
using namespace std;

void bresenhamLine(const int x0, const int y0, const int x1, const int y1)
{
    const int dx = x1 - x0, dy = y1 - y0;
    const int adx = abs(dx), ady = abs(dy);
    int i, step, slope, x = x0, y = y0;

    if (adx >= ady)
    {
        slope = 2 * ady - adx;
        step = adx;
    }
    else
    {
        slope = 2 * adx - ady;
        step = ady;
    }

    cout << endl;
    for (i = 0; i <= step; i++)
    {
        cout << x << ", " << y << endl;
        if (adx >= ady)
        {
            if (dx > 0 && dy >= 0)
            {
                if (slope >= 0)
                {
                    slope -= 2 * dx;
                    y++;
                }
                slope += 2 * dy;
                x++;
            }
            else if (dx > 0 && dy <= 0)
            {
                if (slope >= 0)
                {
                    slope -= 2 * dx;
                    y--;
                }
                slope -= 2 * dy;
                x++;
            }
            else if (dx < 0 && dy >= 0)
            {
                if (slope <= 0)
                {
                    slope -= 2 * dx;
                    y++;
                }
                slope -= 2 * dy;
                x--;
            }
            else if (dx < 0 && dy <= 0)
            {
                if (slope <= 0)
                {
                    slope -= 2 * dx;
                    y--;
                }
                slope += 2 * dy;
                x--;
            }
        }
        else
        {
            if (dy > 0 && dx >= 0)
            {
                if (slope >= 0)
                {
                    slope -= 2 * dy;
                    x++;
                }
                slope += 2 * dx;
                y++;
            }
            else if (dy > 0 && dx <= 0)
            {
                if (slope >= 0)
                {
                    slope -= 2 * dy;
                    x--;
                }
                slope -= 2 * dx;
                y++;
            }
            else if (dy < 0 && dx >= 0)
            {
                if (slope <= 0)
                {
                    slope -= 2 * dy;
                    x++;
                }
                slope -= 2 * dx;
                y--;
            }
            else if (dy < 0 && dx <= 0)
            {
                if (slope <= 0)
                {
                    slope -= 2 * dy;
                    x--;
                }
                slope += 2 * dx;
                y--;
            }
        }
    }
    cout << endl;
}
