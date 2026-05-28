#include <bits/stdc++.h>
using namespace std;

/*
output[0][v]: neighbour "u" of node "v"
output[1][v]: edge weight "u" to "v"
*/

void primMST(const int input[][nodes], int output[2][nodes], const int source = 0)
{
    int visited[nodes] = {0};
    visited[source] = 1;
    fill(output[1], output[1] + nodes, INT_MAX);

    while (accumulate(visited, visited + nodes, 0) != nodes)
    {
        return;
    }
}

void kruskalMST(const int input[][nodes], int output[2][nodes])
{
}

void dijkstraMST(const int input[][nodes], int output[2][nodes])
{
}