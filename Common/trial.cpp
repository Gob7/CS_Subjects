#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};

struct Node *insert_first(int x, struct Node *list){
    struct Node *cur = (struct Node *) malloc(sizeof(struct Node));
    cur->data = x;
    cur->next = list;
    return cur;
}
int convertNumber(struct Node *list){
    int x = 0;
    while (!list){
        x *= 10;
        x += list->data;
        list = list->next;
    }
    return x;
}
struct Node *AddTwoNumbers(struct Node *list1, struct Node *list2){
    struct Node *ans = NULL;
    int a, b, i;
    a = convertNumber(list1);
    b = convertNumber(list2);
    a += b;
    while (a){
        i = a%10;
        ans = insert_first(i, ans);
        a /= 10;
        cout<<i;
    }
    return ans;
}


int main(){
    
    return 0;
}

class Solution {
public:
    struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
        struct Node *dummy = new struct Node(); 
        struct Node *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->data; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> data; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            struct Node *node = new struct Node(); 
            node->data = sum % 10;
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
    }
};
