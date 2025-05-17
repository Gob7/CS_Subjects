// infix to postfix using stack
#include <bits/stdc++.h>
using namespace std;

// precedence of operators
int pcd(char chr)
{
    if (chr == '^')
        return 3;
    else if (chr == '/' || chr == '*' || chr == '%')
        return 2;
    else if (chr == '+' || chr == '-')
        return 1;
    return -1;
}

string convert(string str)
{
    stack<char> stk;
    string post;
    char chr;
    bool flag1, flag2;
    int i, k;

    for (i = 0; i < str.length(); i++)
    {
        chr = str[i];
        flag1 = (chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z') || (chr >= '0' && chr <= '9');
        flag2 = chr == '^' || chr == '/' || chr == '*' || chr == '%' || chr == '+' || chr == '-';

        // if ( -> push
        if (chr == '(' || chr == '{' || chr == '[')
            stk.push(chr);
        // if ) -> pop till (
        else if (chr == ')' || chr == '}' || chr == ']')
        {
            if (chr == ')')
                chr = '(';
            else if (chr == '}')
                chr = '{';
            else
                chr = '[';

            while (!stk.empty() && stk.top() != chr)
            {
                // wrong input
                if (stk.empty())
                    return "";

                post += stk.top();
                stk.pop();
            }
            stk.pop();
        }

        // if variable or integer -> print
        else if (flag1)
            post += chr;
        // if operator -> high precedence: push; low or equal precedence: pop & push (exception ^)
        else if (flag2)
        {
            k = pcd(chr);
            while (!stk.empty() && k <= pcd(stk.top()))
            {
                // if operator and tos are ^ -> push
                if (pcd(stk.top()) == 3 && k == 3)
                    break;
                post += stk.top();
                stk.pop();
            }
            stk.push(chr);
        }

        // wrong input
        else
            return "";
    }
    while (!stk.empty())
    {
        post += stk.top();
        stk.pop();
    }
    return post;
}

int main()
{
    string str;
    cout << "INFIX: ";
    cin >> str;
    cout << "POSTFIX = " << convert(str);
    return 0;
}