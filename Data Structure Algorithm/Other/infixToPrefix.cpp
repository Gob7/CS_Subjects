// infix to prefix using stack
#include <bits/stdc++.h>
using namespace std;

// precedence of operators
int pcd (char chr){
    if (chr == '^') 
        return 3;
    else if (chr == '/' || chr == '*' || chr == '%') 
        return 2;
    else if (chr == '+' || chr == '-') 
        return 1;
    return -1;
}

string convert (string str){
    reverse(str.begin(), str.end());
    stack <char> stk;
    string pre;
    char chr;
    bool flag1, flag2;
    int i, k;

    for(i=0; i<str.length(); i++){
        chr = str[i];
        flag1 = (chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z') || (chr >= '0' && chr <= '9');
        flag2 = chr == '^' || chr == '/' || chr == '*' || chr == '%' || chr == '+' || chr == '-' ;

        // if ) -> push
        if (chr == ')' || chr == '}' || chr == ']')
            stk.push(chr);
        // if ( -> pop till )
        else if (chr == '(' || chr == '{' || chr == '['){
            if (chr == '(') chr = ')';
            else if (chr == '{') chr = '}';
            else chr = ']';

            while (!stk.empty() && stk.top() != chr){
                // wrong input
                if (stk.empty())
                    return "";
                
                pre += stk.top();
                stk.pop();
            }
            stk.pop();
        }

        // if variable or integer -> print
        else if (flag1)
            pre += chr;
        // if operator -> high or equal precedence: push; low precedence: pop & push (exception ^)
        else if (flag2){
            k = pcd(chr);
            // if operator and tos are ^ -> pop & push
            while (!stk.empty() && (k == 3 && pcd(stk.top()) == 3 || k < pcd(stk.top()))){
                pre += stk.top();
                stk.pop();
            }
            stk.push(chr);
        }

        // wrong input
        else 
            return "";
    }
    while (!stk.empty()){
        pre += stk.top();
        stk.pop();
    }
    reverse(pre.begin(), pre.end());
    return pre;
}

int main(){
    string str;
    cout << "INFIX: ";
    cin >> str;
    cout << "PREFIX = " << convert(str);
    return 0;
}