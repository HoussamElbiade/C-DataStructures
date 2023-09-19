#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char val;
    struct Node* next;
};
typedef struct Node Node;

Node* top = NULL;
void push(char c);
char pop();
void Reverse(char* C, int len);
int Strlen(char* C);

int main(int argc, char** argv){
    char C[100] = "1324";
    Reverse(C, Strlen(C));
    printf("%s \n", C);
}
void push(char c){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->next = top;
    new_node->val = c;
    top = new_node;
}

char pop(){
    if(top == NULL){
        return '\0';
    }
    Node* temp = top;
    char c = temp->val;
    top = top->next;
    free(temp);
    return c;
}

void Reverse(char* C, int len){
    if(len == 0){
        printf("Empty String !");
        exit(-1);
    }
    int i = 0 ;
    for(i = 0; i < len; i++){
        push(C[i]);
    }
    for(i = 0; i < len; i++){
        C[i] = pop();
    }
}

int Strlen(char* C){
    int count = 0;
    int i = 0;
    while(C[i] != '\0'){
        count++;
        i++;
    }
    return count;
}


