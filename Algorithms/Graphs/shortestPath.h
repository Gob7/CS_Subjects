#include <bits/stdc++.h>
using namespace std;

// All-Pair Shortest Distance
void floydWarshellDistance(const int input[][nodes], int output[][nodes])
{
    int i, j, k, temp[nodes][nodes];
    copyGraph(input, temp);

    for (k = 0; k < nodes; k++)
    {
        for (i = 0; i < nodes; i++)
        {
            for (j = 0; j < nodes; j++)
            {
                if (temp[i][k] == INT_MAX || temp[k][j] == INT_MAX)
                    output[i][j] = temp[i][j];
                else
                    output[i][j] = min(temp[i][j], temp[i][k] + temp[k][j]);
            }
        }
        // graphPrint(d);
        copyGraph(output, temp);
    }
}

// output[0][v]: parent of node "v"
// output[1][v]: shortest distance to node "v"
void RELAX(const int input[][nodes], int output[2][nodes], const int uNode, const int vNode)
{
    // cout << "\nRELAX called for: u = " << uNode << ", v = " << vNode;
    int temp = output[1][uNode] + input[uNode][vNode];
    if (output[1][vNode] > temp)
    {
        output[0][vNode] = uNode;
        output[1][vNode] = temp;
        // cout << " (update success)";
    }
}

void initSingleSource(int output[2][nodes], const int source)
{
    fill(output[0], output[0] + nodes, INT_MIN);
    fill(output[1], output[1] + nodes, INT_MAX);
    output[0][source] = -1;
    output[1][source] = 0;
}

// Single-Source Shortest Distance 1
void dijkstraDistance(const int input[][nodes], int output[2][nodes], const int source = 0)
{
    int i, j, currentNode, tempDist, visited[nodes] = {0};
    initSingleSource(output, source);

    for (i = 0; i < nodes; i++)
    {
        // Select shortest distance from unvisited node
        tempDist = INT_MAX;
        for (j = 0; j < nodes; j++)
        {
            if (!visited[j] && tempDist > output[1][j])
            {
                currentNode = j;
                tempDist = output[1][j];
            }
        }

        visited[currentNode] = 1;
        for (j = 0; j < nodes; j++)
        {
            if (visited[j])
                continue;
            if (input[currentNode][j] != INT_MAX)
                RELAX(input, output, currentNode, j);
        }
    }
}

// Single-Source Shortest Distance 2
void bellmanFord(const int input[][nodes], int output[2][nodes], int tempDistance[])
{
    int i, j, toVisit[nodes] = {0};

    for (i = 0; i < nodes; i++)
        if (output[1][i] != tempDistance[i])
            toVisit[i] = 1;

    copy(output[1], output[1] + nodes, tempDistance);
    for (i = 0; i < nodes; i++)
    {
        if (!toVisit[i])
            continue;
        for (j = 0; j < nodes; j++)
        {
            if (i == j)
                continue;
            if (input[i][j] != INT_MAX)
                RELAX(input, output, i, j);
        }
    }
}

int bellmanFordDistance(const int input[][nodes], int output[2][nodes], const int source = 0)
{
    int i, toVisit = 0, tempDistance[nodes];
    initSingleSource(output, source);
    fill(tempDistance, tempDistance + nodes, INT_MAX);

    for (i = 0; i < nodes; i++)
        bellmanFord(input, output, tempDistance);

    bellmanFord(input, output, tempDistance);
    for (i = 0; i < nodes; i++)
        if (output[1][i] != tempDistance[i])
            toVisit++;

    return toVisit;
}