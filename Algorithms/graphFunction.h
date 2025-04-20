// nodes is defined in "graph.cpp"
#include <bits/stdc++.h>
using namespace std;

void initGraph(int c[][nodes]){
    for (int i=0; i<nodes; i++){
        fill(c[i], c[i]+nodes, INT_MAX);
        c[i][i] = 0;
    }
}

void initMultiStage(int cost[][nodes], int path[][nodes], int levels){
    for (int i=0; i<levels; i++){
        fill(cost[i], cost[i]+nodes, -1);
        fill(path[i], path[i]+nodes, -1);
    }
}

void pathPrint(int levels, int path[][nodes]){
    int i, j = 0;
    cout<<"\nPath: [ ";
    for (int i=1; i<levels; i++){
        cout<<j+1<<" -> ";
        j = path[i][j];
    }
    cout<<j+1<<" ]\n";
}

void copyGraph(int src[][nodes], int dest[][nodes]){
    for (int i=0; i<nodes; i++)
        copy(src[i], src[i]+nodes, dest[i]);
}

void graphPrint(int c[][nodes]){
    int i, j;

    cout<<"\n  ";
    fill_n(ostream_iterator<char>(cout), 6, '_');
    for (i=0; i<nodes; i++){
        cout<<i+1;
        fill_n(ostream_iterator<char>(cout), 7, '_');
    }
    cout<<"\n |";
    for (i=0; i<=nodes; i++)
        cout<<"\t";
    cout<<"|\n";

    for (i=0; i<nodes; i++){
        cout<<i+1<<"|\t";
        for (j=0; j<nodes; j++){
            if (c[i][j] == INT_MAX)
                cout<<"-"<<"\t";
            else
                cout<<c[i][j]<<"\t";
        }
        cout<<"|\n";
    }
    cout<<" |";
    fill_n(ostream_iterator<char>(cout), (nodes+1)*8-2, '_');
    cout<<"|\n\n";
}