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

void makeGraph(int input[][nodes])
{
    /*
    // 4 nodes
    input[0][1] = 8;
    input[0][3] = 1;

    input[1][2] = 1;

    input[2][0] = 4;

    input[3][1] = 2;
    input[3][2] = 9;
    */
    /*
    // 4 nodes
    input[0][1] = 3;
    input[0][2] = 8;

    input[1][2] = 4;
    input[1][3] = 11;

    input[2][3] = 7;

    input[3][0] = 4;
    */

    // 8 nodes
    input[0][1] = 1;
    input[0][3] = 1;
    input[0][4] = 1;

    input[1][2] = 1;
    input[1][3] = 1;

    input[2][0] = 1;

    input[3][2] = 1;

    input[4][3] = 1;
    input[4][5] = 1;

    input[5][3] = 1;

    input[6][4] = 1;
    input[6][5] = 1;
    input[6][7] = 1;

    input[7][3] = 1;

    /*
    // 12 nodes
    input[0][1] = 9;
    input[0][2] = 7;
    input[0][3] = 3;
    input[0][4] = 2;

    input[1][5] = 4;
    input[1][6] = 2;
    input[1][7] = 1;

    input[2][5] = 2;
    input[2][6] = 7;

    input[3][7] = 11;

    input[4][6] = 11;
    input[4][7] = 8;

    input[5][8] = 6;
    input[5][9] = 5;

    input[6][8] = 4;
    input[6][9] = 3;

    input[7][9] = 5;
    input[7][10] = 6;

    input[8][11] = 4;

    input[9][11] = 2;

    input[10][11] = 3;
    */
}

void initMultiStage(int cost[][nodes], int path[][nodes], int levels)
{
    for (int i = 0; i < levels; i++)
    {
        fill(cost[i], cost[i] + nodes, -1);
        fill(path[i], path[i] + nodes, -1);
    }
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

void copyGraph(const int source[][nodes], int destination[][nodes])
{
    for (int i = 0; i < nodes; i++)
        copy(source[i], source[i] + nodes, destination[i]);
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

void printFeaturesBFS(const int feature[3][nodes], const int trees, const int root = 0)
{
    cout << "\n\nBREADTH First Search\n";
    cout << "\nROOT: " << root << endl;
    cout << "NODE\tLEVEL\tPARENT\n";

    for (int i = 0; i < nodes; i++)
        cout << i << "\t" << feature[1][i] << "\t" << feature[2][i] << endl;

    cout << "\nTrees in forest: " << trees << endl;
}

void printFeaturesDFS(const int feature[3][nodes], const int trees, const int root = 0)
{
    cout << "\n\nDEPTH First Search\n";
    cout << "\nROOT: " << root << endl;
    cout << "NODE\tSTART\tFINISH\tPARENT\n";

    for (int i = 0; i < nodes; i++)
        cout << i << "\t" << feature[1][i] << "\t" << feature[2][i] << "\t" << feature[0][i] << endl;

    cout << "\nTrees in forest: " << trees << endl;
}