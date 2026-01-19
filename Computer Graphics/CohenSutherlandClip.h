/*
Assumptions:
    i.      Clip Window: (x_min, y_min), (x_min, y_max), (x_max, y_min), (x_max, y_max)
    ii.     Line: p0(x0, y0), p1(x1, y1)
    iii.    Region Code: <Top, Bottom, Right, Left>
*/
#include <bits/stdc++.h>
using namespace std;

void assignRegionCode(const int x_min, const int y_min, const int x_max, const int y_max,
                      const int *x, const int *y, int *p)
{
    if (*x < x_min)
        p[3] = 1;
    if (*x > x_max)
        p[2] = 1;
    if (*y < y_min)
        p[1] = 1;
    if (*y > y_max)
        p[0] = 1;
}

int andOperation(const int *p0, const int *p1)
{
    int i, x = 0;
    for (i = 0; i < 4; i++)
        x += p0[i] * p1[i];
    return x;
}

void clippingLine(const int x_min, const int y_min, const int x_max, const int y_max,
                  const int dx, const int dy, int *x, int *y, int *p)
{
    if (p[0])
    {
        *x += round((float)dx / dy * (y_max - *y));
        *y = y_max;
        p[0] = 0;
    }
    if (p[1])
    {
        *x += round((float)dx / dy * (y_min - *y));
        *y = y_min;
        p[1] = 0;
    }
    if (p[2])
    {
        *y += round((float)dy / dx * (x_max - *x));
        *x = x_max;
        p[2] = 0;
    }
    if (p[3])
    {
        *y += round((float)dy / dx * (x_min - *x));
        *x = x_min;
        p[3] = 0;
    }
}

int cohenSutherlandClip(const int x_min, const int y_min, const int x_max, const int y_max,
                        int *x0, int *y0, int *x1, int *y1)
{
    const int dx = *x1 - *x0, dy = *y1 - *y0;
    int p0[4] = {}, p1[4] = {};

    assignRegionCode(x_min, y_min, x_max, y_max, x0, y0, p0);
    assignRegionCode(x_min, y_min, x_max, y_max, x1, y1, p1);

    if (andOperation(p0, p1))
        return 0;

    clippingLine(x_min, y_min, x_max, y_max, dx, dy, x0, y0, p0);
    clippingLine(x_min, y_min, x_max, y_max, dx, dy, x1, y1, p1);

    assignRegionCode(x_min, y_min, x_max, y_max, x0, y0, p0);
    assignRegionCode(x_min, y_min, x_max, y_max, x1, y1, p1);

    if (accumulate(p0, p0 + 4, 0) || accumulate(p1, p1 + 4, 0))
        return 0;
    return 1;
}