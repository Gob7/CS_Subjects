#include <bits/stdc++.h>
using namespace std;

int huffmanCoding(const char *alphabet, const int *frequency, const int length)
{
    int i, newFrequency[length];
    struct node *nodes[length];

    copy(frequency, frequency + length, newFrequency);
    ascending_order(newFrequency, 0, length, 1, nodes);
}