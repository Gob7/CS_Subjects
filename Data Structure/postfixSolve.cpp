// Solving postfix expressions
// use space after each number and operator
#include <bits/stdc++.h>
using namespace std;

int solve(string str)
{
    stack<int> stk;
    string sstr;
    int i, start = -1, end, n, x, y;
    // cout<<str<<endl;

    for (i = 0; i < str.length(); i++)
    {
        // cout<<str[i]<<endl;
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (start == -1)
                start = i;
            end = i;
        }

        else if (str[i] == ' ')
        {
            if (start != -1)
            {
                sstr = str.substr(start, end - start + 1);
                n = stoi(sstr);
                stk.push(n);
                start = -1;
            }
        }

        else
        {
            if (stk.size() < 2)
                return INT_MIN;
            x = stk.top();
            stk.pop();
            y = stk.top();
            stk.pop();

            if (str[i] == '^')
                stk.push(pow(y, x));
            else if (str[i] == '/')
                stk.push(y / x);
            else if (str[i] == '*')
                stk.push(y * x);
            else if (str[i] == '%')
                stk.push(y % x);
            else if (str[i] == '+')
                stk.push(y + x);
            else if (str[i] == '-')
                stk.push(y - x);
            else
                return INT_MIN;
            // cout<<stk.top()<<endl;
        }
    }
    if (stk.size() != 1)
        return INT_MIN;
    return stk.top();
}

int main()
{
    string str;
    cout << "POSTFIX: ";
    getline(cin, str);
    cout << "Solution = " << solve(str);
    return 0;
}