// NFA
#include <stdio.h>
#include <string.h>
int flag = 1;
/*
// 1. string 'ab' & 'ba'
char state[4][2][1] = {{"1", "2"}, {"", "3"}, {"3", ""}, {"", ""}};
int length[4][2] = {{1, 1}, {0, 1}, {1, 0}, {0, 0}};
void nfa(char str[], int current, int i)
{
    if (i == strlen(str) && current == 3)
    {
        if (flag)
            printf("Accepted\n");
        flag = 0;
    }
    for (int j = 0; j < length[current][str[i] - 'a']; j++)
        nfa(str, state[current][str[i] - 'a'][j] - '0', i + 1);
}
*/
/*
// 2. bb*(a+b)
char state[3][2][2] = {{"", "1"}, {"2", "12"}, {"", ""}};
int length[3][2] = {{0, 1}, {1, 2}, {0, 0}};
void nfa(char str[], int current, int i)
{
    if (i == strlen(str) && current == 2)
    {
        if (flag)
            printf("Accepted\n");
        flag = 0;
    }
    for (int j = 0; j < length[current][str[i] - 'a']; j++)
        nfa(str, state[current][str[i] - 'a'][j] - '0', i + 1);
}
*/
/*
// 3. b^ma (m>0) U a^n (n>=0)
char state[4][2][1] = {{"1", "2"}, {"1", ""}, {"3", "2"}, {"", ""}};
int length[4][2] = {{1, 1}, {1, 0}, {1, 1}, {0, 0}};
void nfa(char str[], int current, int i)
{
    if (i == strlen(str) && (current == 3 || current == 1 || current == 0))
    {
        if (flag)
            printf("Accepted\n");
        flag = 0;
    }
    for (int j = 0; j < length[current][str[i] - 'a']; j++)
        nfa(str, state[current][str[i] - 'a'][j] - '0', i + 1);
}
*/
// 4. aba^m (m>=0) U abab^n (n>=0)
char state[5][2][2] = {{"1", ""}, {"", "23"}, {"2", ""}, {"4", ""}, {"", "4"}};
int length[5][2] = {{1, 0}, {0, 2}, {1, 0}, {1, 0}, {0, 1}};
void nfa(char str[], int current, int i)
{
    if (i == strlen(str) && (current == 2 || current == 4))
    {
        if (flag)
            printf("Accepted\n");
        flag = 0;
    }
    for (int j = 0; j < length[current][str[i] - 'a']; j++)
        nfa(str, state[current][str[i] - 'a'][j] - '0', i + 1);
}

void main()
{
    char str[100];
    while (1)
    {
        printf("\nEnter string: ");
        gets(str);
        nfa(str, 0, 0);
        if (flag)
            printf("Rejected\n");
        flag = 1;
    }
}