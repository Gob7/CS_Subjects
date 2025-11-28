// nodes is defined in "graph.cpp"
#include <bits/stdc++.h>
using namespace std;

void initGraph(int input[][nodes])
{
    for (int i = 0; i < nodes; i++)
    {
        fill(input[i], input[i] + nodes, INT_MAX);
        input[i][i] = 0;
    }
}

void initMultiStageGraph(int cost[][nodes], int path[][nodes], const int levels)
{
    for (int i = 0; i < levels; i++)
    {
        fill(cost[i], cost[i] + nodes, -1);
        fill(path[i], path[i] + nodes, -1);
    }
}

void initUndirectedGraph(int input[][nodes])
{
    for (int i = 0; i < nodes; i++)
        for (int j = i + 1; j < nodes; j++)
            input[i][j] = input[j][i] = min(input[i][j], input[j][i]);
}

void copyGraph(const int source[][nodes], int destination[][nodes])
{
    for (int i = 0; i < nodes; i++)
        copy(source[i], source[i] + nodes, destination[i]);
}

void pathPrint(const int levels, const int path[][nodes])
{
    int i, j = 0;
    cout << "\nPath: [ ";
    for (int i = 1; i < levels; i++)
    {
        cout << j + 1 << " -> ";
        j = path[i][j];
    }
    cout << j + 1 << " ]\n\n";
}

void printGraph(const int input[][nodes])
{
    int i, j, x;

    // top
    cout << "\n   ";
    x = 7;
    fill_n(ostream_iterator<char>(cout), x - 1, '_');
    for (i = 0; i < nodes; i++)
    {
        x = i > 9 ? 6 : 7;
        cout << i;
        fill_n(ostream_iterator<char>(cout), x, '_');
    }

    cout << "\n  |";
    for (i = 0; i <= nodes; i++)
        cout << "\t";
    cout << " |\n";

    // middle
    for (i = 0; i < nodes; i++)
    {
        if (i < 10)
            cout << i << " |\t";
        else
            cout << i << "|\t";

        for (j = 0; j < nodes; j++)
        {
            if (input[i][j] == INT_MAX)
                cout << "-" << "\t";
            else
                cout << input[i][j] << "\t";
        }
        cout << " |\n";
    }

    // bottom
    cout << "  |";
    fill_n(ostream_iterator<char>(cout), (nodes + 1) * 8 - 2, '_');
    cout << "|\n\n";
}

void printFeaturesBFS(const int feature[2][nodes], const int trees, const int root = 0)
{
    cout << "\n\nBREADTH First Search\n";
    cout << "\nROOT: " << root << endl;
    cout << "NODE\tLEVEL\tPARENT\n";

    for (int i = 0; i < nodes; i++)
        cout << i << "\t" << feature[0][i] << "\t" << feature[1][i] << endl;

    cout << "\nTrees in forest: " << trees << endl;
}

void printFeaturesDFS(const int feature[2][nodes], const int trees, const int root = 0)
{
    cout << "\n\nDEPTH First Search\n";
    cout << "\nROOT: " << root << endl;
    cout << "NODE\tSTART\tFINISH\n";

    for (int i = 0; i < nodes; i++)
        cout << i << "\t" << feature[0][i] << "\t" << feature[1][i] << endl;

    cout << "\nTrees in forest: " << trees << endl;
}