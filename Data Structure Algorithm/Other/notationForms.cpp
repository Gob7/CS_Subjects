#include <bits/stdc++.h>
using namespace std;

#define postfix true
#define prefix false
#define high 3
#define mid 2
#define low 1
#define err 0

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}
bool isVariable(char c)
{
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}
bool isOperand(char c)
{
    return isVariable(c) || isDigit(c);
}
bool isOperator(char c)
{
    return c == '^' || c == '/' || c == '*' || c == '%' || c == '+' || c == '-';
}
bool isOpen(char c)
{
    return c == '(' || c == '{' || c == '[';
}
bool isClose(char c)
{
    return c == ')' || c == '}' || c == ']';
}

char bracket(char c)
{
    if (c == '(')
        return ')';
    if (c == ')')
        return '(';
    if (c == '{')
        return '}';
    if (c == '}')
        return '{';
    if (c == '[')
        return ']';
    if (c == ']')
        return '[';
    return '\0';
}
int precedence(char c)
{
    if (c == '^')
        return high;
    if (c == '/' || c == '*' || c == '%')
        return mid;
    if (c == '+' || c == '-')
        return low;
    return err;
}
int applyOperator(int a, int b, char c)
{
    switch (c)
    {
    case '^':
        return pow(a, b);
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '%':
        return a % b;
    case '+':
        return a + b;
    case '-':
        return a - b;
    default:
        return INT_MIN;
    }
}

string convert(string str, bool flag)
{
    stack<char> stk;
    string result;
    int precedence_c, precedence_top, loop;

    if (!flag)
        reverse(str.begin(), str.end());

    for (char c : str)
    {
        if (c == ' ')
            continue;

        if (flag ? isOpen(c) : isClose(c))
            stk.push(c);

        else if (flag ? isClose(c) : isOpen(c))
        {
            while (!stk.empty() && stk.top() != bracket(c))
            {
                result += stk.top();
                stk.pop();
            }
            if (stk.empty())
                return "";
            stk.pop();
        }

        else if (isOperand(c))
            result += c;

        else if (isOperator(c))
        {
            precedence_c = precedence(c);
            while (!stk.empty())
            {
                precedence_top = precedence(stk.top());
                // postfix: left-associative, ^ is right (don't pop equal ^)
                // prefix:  right-associative, ^ pops equal ^
                loop = flag ? (precedence_c < precedence_top || precedence_c == precedence_top && precedence_c != high)
                            : (precedence_c < precedence_top || precedence_c == precedence_top && precedence_c == high);
                if (!loop)
                    break;

                result += stk.top();
                stk.pop();
            }
            stk.push(c);
        }

        else
            return "";
    }

    while (!stk.empty())
    {
        if (!isOperator(stk.top()))
            return "";
        result += stk.top();
        stk.pop();
    }

    if (!flag)
        reverse(result.begin(), result.end());
    return result;
}

int solve(string str, bool flag)
{
    stack<int> stk;
    int i, start = -1, end, operand1, operand2, result;

    if (!flag)
        reverse(str.begin(), str.end());

    for (i = 0; i < str.length(); i++)
    {
        if (isDigit(str[i]))
        {
            if (start == -1)
                start = i;
            end = i;
        }

        else if (str[i] == ' ')
        {
            if (start != -1)
            {
                stk.push(stoi(str.substr(start, end - start + 1)));
                start = -1;
            }
        }

        else
        {
            if (stk.size() < 2u)
                return INT_MIN;

            if (flag)
            {
                operand2 = stk.top();
                stk.pop();
                operand1 = stk.top();
                stk.pop();
            }
            else
            {
                operand1 = stk.top();
                stk.pop();
                operand2 = stk.top();
                stk.pop();
            }

            result = applyOperator(operand1, operand2, str[i]);
            if (result == INT_MIN)
                return INT_MIN;
            stk.push(result);
        }
    }

    if (stk.size() != 1u)
        return INT_MIN;
    return stk.top();
}

void printExpression(const string &s, int flag)
{
    if (!flag)
        cout << "\nPREFIX\t\t=";
    else if (flag == -1)
        cout << "INFIX\t\t=";
    else
        cout << "POSTFIX\t\t=";

    if (s.empty())
    {
        cout << " Error" << endl;
        return;
    }
    for (char c : s)
        cout << ' ' << c;
    cout << endl;
}
void printResult(int result)
{
    cout << "Solution\t= "
         << (result == INT_MIN ? "Error" : to_string(result))
         << endl;
}

int main()
{
    // use space after each operand and operator
    string str, s;

    // takes single length digit/variable
    cout << "\nExpression\t: ";
    getline(cin, str);

    s = convert(str, prefix);
    printExpression(s, prefix);

    s = s.empty() ? "" : str;
    printExpression(s, -1);

    s = convert(str, postfix);
    printExpression(s, postfix);

    // takes multiple length integers
    cout << "\n\nPOSTFIX\t\t: ";
    getline(cin, str);
    printResult(solve(str, postfix));

    cout << "\nPREFIX\t\t: ";
    getline(cin, str);
    printResult(solve(str, prefix));

    return 0;
    // cin >> str;
    // cin.ignore();
}