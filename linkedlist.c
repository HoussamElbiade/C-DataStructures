#include <stdlib.h>
#include <stdio.h>

struct Node
{   
    int val;
    struct Node* next;
};

typedef struct Node Node;

void Insert(Node** head, int data);
void PrintList(Node** head);
void InsertAtPos(Node** head, int pos, int data);
int ListSize(Node** head);
void DeleteAtPos(Node** head, int pos);
void Reverse(Node** head);
void RecReverse(Node** head);
void RecusionPrint(Node** head);
void RecusionPrintRev(Node** head);

int main(int argc, char* argv[]){
    Node* head = NULL;
    Insert(&head, 6);
    Insert(&head, 4);
    Insert(&head, 2);
    // PrintList(&head);
    InsertAtPos(&head, 3, 8);
    // PrintList(&head);
    DeleteAtPos(&head, 2);
    PrintList(&head);
    // Reverse(&head);
    RecReverse(&head);
    PrintList(&head);


    
}
void Insert(Node** head, int data){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->val = data;
    new_node->next = *head;
    *head = new_node;
}
void PrintList(Node** head){
    Node* current_node = *head;
    while(current_node != NULL){
        printf("%d -> ",current_node->val);
        current_node = current_node->next;
    }
    printf(" NULL\n");
}
int ListSize(Node** head){
    if(*head == NULL){
        return 0;
    }
    else{
        Node* current_node = *head;
        int i = 0;
        while(current_node != NULL){
            i++;
            current_node = current_node->next;
        }
        return i;
    }
}
void InsertAtPos(Node** head, int pos, int data){
    int len = ListSize(head);
    if(pos < 1 || pos > ListSize(head)){
        printf("Position Not valid!\nPosition must be between 1 and %d\n",len);
        exit(-1);
    }
    if(*head == NULL || pos == 1){
        Insert(head, data);
    }else{
        Node* current_node = *head;
        int i = 1;
        while(i < pos - 1){
            current_node = current_node->next;
            i++;
        }
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->next = current_node->next;
        new_node->val = data;
        current_node->next = new_node;
    }
}
void DeleteAtPos(Node** head, int pos){
    if(pos < 1 || pos > ListSize(head)){
        printf("Position Not valid!\nPosition must be between 1 and %d\n",ListSize(head));
        exit(-1);
    }
    if(*head == NULL){
        printf("List is Empty !\n");
        exit(-1);
    }
    else{
        if(pos != 1){
            Node* prev_node = *head;
            Node* current_node = *head;
            int i = 1;
            while(current_node != NULL && i < pos){
                prev_node = current_node;
                current_node = current_node->next;
                i++;
            }
            prev_node->next = current_node->next;
            free(current_node);
        }
        else{
            Node* temp = *head;
            *head = temp->next;
            free(temp);
        }
    }
}
void Reverse(Node** head){
    if(*head == NULL){
        printf("List is Empty !\n");
        exit(-1);
    }
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = *head;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
void RecReverse(Node** head){
    Node* temp = *head;
    if(temp->next == NULL){
        *head = temp;
        return;
    }
    RecReverse(&(temp->next));
    Node* q = temp->next;
    q->next = temp;
    temp->next = NULL;
}
void RecusionPrint(Node** head){
    if(*head == NULL){
        printf(" NULL\n");
        return; // pay attention : return in void funt is not equivilant to exit(0)
    }
    else{
        Node* temp = *head;
        printf("%d -> ",temp->val);
        RecusionPrint(&(temp->next));
    }
}

void RecusionPrintRev(Node** head){
    if(*head == NULL){
        return; // pay attention : return in void funt is not equivilant to exit(0)
    }
    else{
        Node* temp = *head;
        RecusionPrintRev(&(temp->next));
        printf("%d -> ",temp->val);
    }
}

