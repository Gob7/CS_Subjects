#include <bits/stdc++.h>
using namespace std;

treeNode *createNode(const char alpha, const int freq)
{
    treeNode *ptr = new treeNode;

    ptr->height = alpha; // character
    ptr->value = freq;
    ptr->left = nullptr;
    ptr->right = nullptr;

    return ptr;
}

void sortTreeNodes(treeNode **nodes, const int len)
{
    int i, freq[len];
    for (i = 0; i < len; i++)
        freq[i] = nodes[i]->value;

    descending_order(freq, 0, len, 1, nodes);
}

unsigned int printHuffman(treeNode *ptr, string code)
{
    if (!ptr)
        return 0;
    if (!ptr->left && !ptr->right)
    {
        cout << ptr->height << " : " << ptr->value << "\t-> " << code << endl;
        return ptr->value * code.size();
    }
    unsigned int x1 = printHuffman(ptr->left, code + '0');
    unsigned int x2 = printHuffman(ptr->right, code + '1');
    return x1 + x2;
}

void huffmanCoding(const char *alphabet, const int *frequency, const int length)
{
    unsigned int i;
    treeNode *nodes[length];

    for (i = 0; i < length; i++)
        nodes[i] = createNode(alphabet[i], frequency[i]);

    for (i = 1; i < length; i++)
    {
        sortTreeNodes(nodes, length - i + 1);
        treeNode *ptr = new treeNode;

        ptr->left = nodes[length - i];
        ptr->right = nodes[length - i - 1];
        ptr->value = ptr->left->value + ptr->right->value;
        nodes[length - i - 1] = ptr;
    }

    i = printHuffman(nodes[0], "");
    cout << "Total\t=  " << i << endl;
}