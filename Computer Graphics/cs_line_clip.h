/*Cohen Sutherland line clipping algorithm
Assumptions:
    i.      Clip Window: (x_min, y_min), (x_min, y_max), (x_max, y_min), (x_max, y_max)
    ii.     Line: p0(x0, y0), p1(x1, y1)
    iii.    Region Code: <Top, Bottom, Right, Left>
*/
#include <bits/stdc++.h>
using namespace std;

void code(int x_min, int y_min, int x_max, int y_max, int *x, int *y, int *p)
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
int and_code(int *p0, int *p1)
{
    int i, x = 0;
    for (i = 0; i < 4; i++)
        x += p0[i] * p1[i];
    return x;
}
void clipping(int x_min, int y_min, int x_max, int y_max, int dx, int dy, int *x, int *y, int *p)
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
void clip(int x_min, int y_min, int x_max, int y_max, int *x0, int *y0, int *x1, int *y1, int *c)
{
    int p0[4] = {}, p1[4] = {}, i;
    *c = 0;
    code(x_min, y_min, x_max, y_max, x0, y0, p0);
    code(x_min, y_min, x_max, y_max, x1, y1, p1);
    if (and_code(p0, p1))
        return;

    int dx = *x1 - *x0, dy = *y1 - *y0;
    clipping(x_min, y_min, x_max, y_max, dx, dy, x0, y0, p0);
    clipping(x_min, y_min, x_max, y_max, dx, dy, x1, y1, p1);

    code(x_min, y_min, x_max, y_max, x0, y0, p0);
    code(x_min, y_min, x_max, y_max, x1, y1, p1);
    if (!(accumulate(p0, p0 + 4, 0)) && !(accumulate(p1, p1 + 4, 0)))
        *c = 1;
}