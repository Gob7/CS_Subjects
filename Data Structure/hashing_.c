// Collision Reduction Technique (Separate Chaining)
#include <stdio.h>
#include <stdlib.h>
#define max 10
struct node {
    int data;
    struct node *next;
} *memory[max];

void traverse(){
    printf("\nMemory contains:\n");
    struct node *ptr;
    for (int index=0; index<max; index++){
        ptr = memory[index];
        printf("%d\t-> ", index);
        while (ptr){
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}
void sepChain(int key){
    struct node *cur = (struct node *) malloc(sizeof(struct node));
    int index = key % max;
    if (!cur){
        printf("Space not available.\n");
        return;
    }
    cur->data = key;
    cur->next = memory[index];
    memory[index] = cur;
}
void delete(int key){
    struct node *ptr, *cur;
    int index = key % max;
    cur = memory[index];
    ptr = NULL;
    while (cur){
        if (cur->data == key){
            if (!ptr)
                memory[index] = cur->next;
            else
                ptr->next = cur->next;
            free(cur);
            break;
        }
        ptr = cur;
        cur = cur->next;
    }
}

void main(){
    sepChain(77);
    sepChain(11);
    sepChain(34);
    sepChain(59);
    sepChain(17);
    sepChain(27);
    sepChain(47);
    sepChain(93);
    sepChain(69);
    sepChain(84);
    sepChain(81);
    sepChain(15);
    traverse();
    delete(10);
    delete(93);
    delete(84);
    delete(59);
    delete(17);
    traverse();
}