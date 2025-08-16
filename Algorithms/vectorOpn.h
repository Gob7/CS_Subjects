#include <bits/stdc++.h>
using namespace std;

vector<int> trimmer(vector<int> vec)
{
    int i = vec.size() - 1;
    while (i > -1 && !vec[i])
    {
        vec.pop_back();
        i--;
    }
    if (vec.size() == 0)
        vec.push_back(0);

    return vec;
}

vector<int> intToVec(int num)
{
    vector<int> vec;
    if (!num)
        vec.push_back(0);
    while (num)
    {
        vec.push_back(num % 10);
        num /= 10;
    }
    return vec;
}

vector<int> pushIntToVec(vector<int> vec, int num)
{
    while (num)
    {
        vec.push_back(num % 10);
        num /= 10;
    }
    return vec;
}

vector<int> pushZero(vector<int> vec, int n)
{
    for (int i = 0; i < n; i++)
        vec.insert(vec.begin(), 0);
    return vec;
}