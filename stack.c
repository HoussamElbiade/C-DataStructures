#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node* next;
};
typedef struct Node Node;
Node* top = NULL;
void push(int data);
void pop();
void disp(Node* head);

int main(int argc, char* argv[]){
    push(1);
    push(2);
    push(3);
    push(4);
    disp(top);
    printf("\n");
    pop();
    disp(top);
}
void push(int data){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->next = top;
    new_node->val = data;
    top = new_node;
}

void pop(){
    if(top == NULL){
        printf("Empty stack!!");
        return;
    }
    Node* temp = top;
    top = top->next;
    free(temp);
}

void disp(Node* head){
    if(head == NULL){
        return;
    }
    disp(head->next);
    printf("%d ", head->val);
}
