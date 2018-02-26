#include <stdio.h>
#include <stdlib.h>

int SIZE = 5;
int STACK[5];
int top = -1;

int Is_Full(){
    if (top == SIZE){
        return 1;
    }else
    return 0;
}

int Is_Empty(){
    if(top == -1){
        return 1;
    }else
    return 0;
}

void push(int data){
    if(!Is_Full()){
        STACK[++top] = data;
    }else
    printf("stack is full");
}

int pop(){
    if(!Is_Empty()){
        return STACK[top--];
    }else
  printf("stack is empty");
}


int main()
{
    push(2);
    push(4);
    printf("%d\n", pop());
    printf("%d ", pop());
    return 0;
}
