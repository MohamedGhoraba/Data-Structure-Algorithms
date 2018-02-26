#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Hash_item
{
    int data;
    int key;
};

const int size = 20;
typedef struct Hash_item Node;
Node *Hash_table[size];
Node *Deleted_item;
Node *Item;
int Hash_code(int key)
{
    return key % size;
}

void Insert(int key, int data)
{
    int Hash_index;
    Node *item = (Node*) malloc(sizeof(Node));
    item->data = data;
    item->key = key;
    Hash_index = Hash_code(key);
    while(Hash_table[Hash_index] != NULL && Hash_table[Hash_index]->key != -1)
    {
        Hash_index++;
        Hash_index %= size;
    }

    Hash_table[Hash_index] = item;
}

Node *Search(int key)
{
    int Hash_index = Hash_code(key);
    while(Hash_table[Hash_index] != NULL)
    {
        if(Hash_table[Hash_index]->key == key)
            return Hash_table[Hash_index];
        Hash_index++;
        Hash_index %= size;
    }
}

void Delete(Node *item)
{
    int key = item->key;
    int Hash_index = Hash_code(key);
    while(Hash_table[Hash_index] != NULL)
    {
        if(Hash_table[Hash_index]->key == key)
            Hash_table[Hash_index] = Deleted_item;
        Hash_index++;
        Hash_index %= size;
    }
}

void Display()
{
    for(int i = 0; i < size; i++)
    {
        if(Hash_table[i] != NULL)
            printf("(%d,%d) \n", Hash_table[i]->key,Hash_table[i]->data);
    }
}

int main()
{
    Deleted_item = (Node*) malloc(sizeof(Node));
    Deleted_item->data = -1;
    Deleted_item->key = -1;

    Insert(1,20);
    Insert(2,70);
    Insert(42,80);
    Insert(4,25);
    Insert(12,44);
    Insert(14,32);
    Display();
    printf("*****************\n");
    Item = Search(12);
    Delete(Item);
    Display();
    return 0;
}
