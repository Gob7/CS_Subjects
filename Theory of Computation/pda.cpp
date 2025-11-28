#include <bits/stdc++.h>
using namespace std;
stack<char> pda;

// push down autometa to accept {0^n 1^n}
void q1(char str[], int i);
void q0(char str[], int i)
{
    if (strlen(str) == i)
    {
        cout << "Rejected\n";
        return;
    }
    if (str[i] == '0')
    {
        pda.push('0');
        q0(str, i + 1);
    }
    else if (!pda.empty())
    {
        pda.pop();
        q1(str, i + 1);
    }
    else
    {
        cout << "Rejected\n";
        return;
    }
}
void q1(char str[], int i)
{
    if (strlen(str) == i)
    {
        if (pda.empty())
            cout << "Accepted\n";
        else
            cout << "Rejected\n";
        return;
    }
    if (str[i] == '1' && !pda.empty())
    {
        pda.pop();
        q1(str, i + 1);
    }
    else
    {
        cout << "Rejected\n";
        return;
    }
}

int main()
{
    char str[100];
    while (1)
    {
        printf("\nEnter string: ");
        gets(str);
        while (!pda.empty())
            pda.pop();
        q0(str, 0);
    }
    return 0;
}