// Stack using array
#include <stdio.h>
#define limit 7
int key = -1;
int stack[limit];

int isEmpty(){
    if (key == -1)
        return 1;
    return 0;
}
int isFull(){
    if (key == limit-1)
        return 1;
    return 0;
}

void push(int x){
    if (isFull()){
        printf("\nStack Overflow.\n");
        return;
    }
    stack[++key] = x;
    printf("%d is pushed.\n", stack[key]);
}
void pop(){
    if (isEmpty()){
        printf("\nStack Underflow.\n");
        return;
    }
    printf("%d is popped.\n", stack[key--]);
}

void peek(){
    if (isEmpty()){
        printf("\nStack Underflow.\n");
        return;
    }
    printf("%d is peeked.\n",stack[key]);
}
void show(){
    if (isEmpty()){
        printf("\nStack Underflow.\n");
        return;
    }
    printf("\nStack contains:\n");
    for (int i=key; i>-1; i--)
        printf("%d\n", stack[i]);
    printf("\n");
}

void main(){
    pop();
    peek();
    show();

    push(5);
    push(8);
    push(3);
    push(4);
    push(0);
    push(5);
    push(2);
    push(9);
    push(7);
    show();

    pop();
    pop(); 
    peek();
    pop();
    pop();
    peek();
    push(9);
    push(7);
    show();
}