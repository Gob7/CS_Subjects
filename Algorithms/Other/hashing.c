// Collision Reduction Techniques in Hashing
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define max 10
int memoryArray[max];
static int memoryArrayFilled = 0;
struct node
{
    int data;
    struct node *next;
} *memoryList[max];

void init()
{
    for (int i = 0; i < max; i++)
        memoryArray[i] = INT_MIN;
}

// Linear Probing: H(k, i) = {h(k) + i} % m
// Primary Clustering Problem
void linearProbing(int key, int hash, int i)
{
    int index = (hash + i) % max;
    if (memoryArray[index] == INT_MIN)
    {
        memoryArray[index] = key;
        return;
    }
    else
        linearProbing(key, hash, i + 1);
}

// Quadratic Probing: H(k, i) = {h(k) + i^2} % m
// Secondary Clustering Problem
void quadraticProbing(int key, int hash, int i)
{
    int p = pow(i, 2);
    int index = (hash + p) % max;
    if (memoryArray[index] == INT_MIN)
    {
        memoryArray[index] = key;
        return;
    }
    else
        quadraticProbing(key, hash, i + 1);
}

// Cubic Probing: H(k, i) = {h(k) + i^3} % m
// Better than Quadratic Probing
void cubicProbing(int key, int hash, int i)
{
    int p = pow(i, 3);
    int index = (hash + p) % max;
    if (memoryArray[index] == INT_MIN)
    {
        memoryArray[index] = key;
        return;
    }
    else
        cubicProbing(key, hash, i + 1);
}

// Double   :   h'(k) = k % (m-1) + 1               [ h'(k) != 0 ]
// Hashing  :   H(k, i) = {h(k) + i*h'(k)} % m
// Computational Overhead
void doubleHashing(int key, int hash, int hash_new, int i)
{
    // can be optimized by calculating hash_new only once in "openAddressing"
    if (!hash_new)
        hash_new = key % (max - 1) + 1;

    int index = (hash + i * hash_new) % max;
    if (memoryArray[index] == INT_MIN)
    {
        memoryArray[index] = key;
        return;
    }
    else
        doubleHashing(key, hash, hash_new, i + 1);
}

// Hash function: h(k) = k % m
void openAddressing(int key)
{
    if (memoryArrayFilled == max)
        return;
    memoryArrayFilled++;
    int index = key % max;

    if (memoryArray[index] == INT_MIN)
        memoryArray[index] = key;

    // RUN THE FOLLOWING ONE AT A TIME
    else
    {
        // linearProbing(key, index, 1);
        // quadraticProbing(key, index, 1);
        cubicProbing(key, index, 1);
        // doubleHashing(key, index, 0, 1);
    }
}

void printArray()
{
    printf("\nmemoryArray contains:");
    for (int index = 0; index < max; index++)
    {
        printf("\n%d\t-> ", index);
        if (memoryArray[index] != INT_MIN)
            printf("%d", memoryArray[index]);
        else
            printf("NULL");
    }
    printf("\n");
}

void traverseList()
{
    printf("\nmemoryList contains:\n");
    struct node *ptr;
    for (int index = 0; index < max; index++)
    {
        ptr = memoryList[index];
        printf("%d\t-> ", index);
        while (ptr)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("X\n");
    }
}

// Can use AVL tree or BST instead of linked list
void separateChaining(int key)
{
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    int index = key % max;
    if (!cur)
    {
        printf("Space not available.\n");
        return;
    }
    cur->data = key;
    cur->next = memoryList[index];
    memoryList[index] = cur;
}

// Deletion is easier in separate chaining
void deleteFromList(int key)
{
    struct node *ptr, *cur;
    int index = key % max;
    cur = memoryList[index];
    ptr = NULL;
    while (cur)
    {
        if (cur->data == key)
        {
            if (!ptr)
                memoryList[index] = cur->next;
            else
                ptr->next = cur->next;
            free(cur);
            break;
        }
        ptr = cur;
        cur = cur->next;
    }
}

void main()
{
    // Change according to the probing technique (openAddressing function)
    printf("Open Addressing\t");
    // printf("(Linear Probing)\n");
    // printf("(Quadratic Probing)\n");
    printf("(Cubic Probing)\n");
    // printf("(Double Hashing)\n");
    printf("------------------------------------------------\n");

    init();
    // printArray();
    openAddressing(77);
    openAddressing(34);
    openAddressing(59);
    openAddressing(17);
    openAddressing(27);
    openAddressing(47);
    openAddressing(69);
    openAddressing(84);
    openAddressing(93);
    printf("memoryArrayFilled = %d", memoryArrayFilled);
    printArray();

    printf("\n\n\n\nSeparate Chaining\n");
    printf("------------------------------------------------\n");
    separateChaining(77);
    separateChaining(11);
    separateChaining(34);
    separateChaining(59);
    separateChaining(17);
    separateChaining(4190);
    separateChaining(27);
    separateChaining(7);
    separateChaining(100);
    separateChaining(47);
    separateChaining(69);
    separateChaining(84);
    separateChaining(81);
    separateChaining(15);
    separateChaining(93);
    traverseList();

    deleteFromList(10); // not in list
    deleteFromList(11);
    deleteFromList(81);
    deleteFromList(15);
    deleteFromList(7);
    deleteFromList(0); // not in list
    printf("\n\nAfter deleting 11, 81, 15, 7");
    traverseList();
}
