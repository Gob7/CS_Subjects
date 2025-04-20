// Collision Reduction Technique (Open Addressing)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#define max 10
int memory[max];
int flag = 0;
void init(){
    for (int i=0; i<max; i++)
        memory[i] = INT_MIN;
}

// Linear Probing: H(k, i) = {h(k) + i} % m
void lineProbe(int key, int hash, int i){
    int index = (hash + i) % max;
    if (memory[index] == INT_MIN){
        memory[index] = key;
        return;
    }
    else
        lineProbe(key, hash, i+1);
}
// Quadratic Probing: H(k, i) = {h(k) + i^2} % m
void quadProbe(int key, int hash, int i){
    int p = pow(i, 2);
    int index = (hash + p) % max;
    if (memory[index] == INT_MIN){
        memory[index] = key;
        return;
    }
    else
        quadProbe(key, hash, i+1);
}
// Double Hashing:  h'(k) = k % (m-1) + 1               h'(k) != 0
//                  H(k, i) = {h(k) + i*h'(k)} % m
void doubHash(int key, int hash, int hash_new, int i){
    if (!hash_new)
        hash_new = key % (max-1) + 1;

    int index = (hash + i*hash_new) % max;
    if (memory[index] == INT_MIN){
        memory[index] = key;
        return;
    }
    else
        doubHash(key, hash, hash_new, i+1);
}

// Hash function: h(k) = k % m
void hashFun(int key){
    if (flag == max)
        return;
    flag++;
    int index = key % max;

    if (memory[index] == INT_MIN)
        memory[index] = key;
    else
        lineProbe(key, index, 1);
        // quadProbe(key, index, 1);
        // doubHash(key, index, 0, 1);
}
void print(){
    printf("\nMemory contains:");
    for (int index=0; index<max; index++){
        printf("\n%d\t-> ", index);
        if (memory[index] != INT_MIN)
            printf("%d", memory[index]);
        else
            printf("NULL");
    }
    printf("\n");
}

void main(){
    init();
    // print();

    hashFun(77);
    hashFun(34);
    hashFun(59);
    hashFun(17);
    hashFun(27);
    hashFun(47);
    hashFun(69);
    hashFun(84);
    hashFun(93);
    printf("flag = %d", flag);
    print();
}
