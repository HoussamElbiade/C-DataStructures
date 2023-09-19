#include <iostream>
#include <stack>

struct Node
{   
    int val;
    struct Node* next;
};

void Insert(Node** head, int data);
void Reverse(Node** head);
void PrintList(Node** head);

int main(int argc, char** argv){
    Node* head = nullptr;
    Insert(&head, 6);
    Insert(&head, 4);
    Insert(&head, 2);
    PrintList(&head);
    Reverse(&head);
    PrintList(&head);
    return 0;
}
void Insert(Node** head, int data){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->val = data;
    new_node->next = *head;
    *head = new_node;
}
void Reverse(Node** head){
    if(*head == nullptr){
        std::cout<<"Empty String"<<std::endl;
        return;
    }
    std::stack<Node*> S;
    Node* temp = *head;
    while(temp != nullptr){
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top();
    *head = temp;
    S.pop();
    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = nullptr;
}

void PrintList(Node** head){
    Node* current_node = *head;
    while(current_node != NULL){
        std::cout<<current_node->val;
        std::cout<<" -> ";
        current_node = current_node->next;
    }
    std::cout<<" NULL"<<std::endl;
}
