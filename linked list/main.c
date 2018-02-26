#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct node{
    int data;
    struct node *next;
};

typedef struct node NODE;
NODE *Head = NULL;
NODE *current = NULL;

void insert(int data){
    NODE *NewNode = (NODE*)malloc(sizeof(NODE));
    NewNode->data = data;
    if(Head == NULL){
        Head = NewNode;
        NewNode->next = NULL;
    }
    else{
        NewNode->next = Head;
        Head = NewNode;
        }
}

void displaylist(){
    NODE *ptr = Head;
   while(ptr)
        {
        printf("%d ",ptr->data);
        ptr = ptr->next;
        }
}

void Search(int data){
    NODE *ptr = Head;
    while(ptr){
        if(ptr->data == data){
            printf("Found");
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("Not Found");
    }
}

void Delete(int data){
    NODE *ptr = Head;
    NODE *last;
    if(Head->data == data){
        Head = Head->next;
    }
    else{
    while(ptr){

        if(ptr->data == data){
            last->next = ptr->next;
        }
        last = ptr;
        ptr = ptr->next;
        }
    }
}

int length(){
    int length = 0;
    for(current = Head; current != NULL; current = current->next){
        length++;
    }
    return length;
}

int main()
{
    insert(2);
    insert(4);
    insert(6);
    displaylist();
    printf("\n");
    Delete(6);
    displaylist();
    printf("\n");
    Search(1);
    printf("\n %d",length());
    return 0;
}
