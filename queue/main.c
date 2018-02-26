#include <stdio.h>
#include <stdlib.h>

int size = 5;
int maxsize = 6;
int front = 5, rear = 5;
int queue[5];

int Is_Full(){
    return ((rear + 1) % maxsize) == front;
}

int Is_Empty(){
    return rear == front;
}

void Enqueue(int data){
    if(!Is_Full()){
        rear = (rear + 1) % maxsize;
        queue[rear] = data;
    }else
        printf("queue is full");
}

int Dequeue(){
    if(!Is_Empty()){
        front = (front + 1) % maxsize;
        return queue[front];
    }else
        printf(" queue is empty");
}

int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    printf("%d\n", Dequeue());
    Enqueue(6);
    printf("%d\n", Dequeue());
    return 0;
}
