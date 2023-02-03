#include<stdio.h>
#include<stdlib.h>

struct node                //make node for linked list using structure
{
    int value;            //value part of node contains the element
    struct node *next;    //the next part of node contains the address of next element of list
};

struct node *head;    //contains the address of first element of linked list

void init()
{
    head=NULL;    //initialize the beginning(head) of list to NULL
}

int main()
{
    printf("Node Created!");
    return 0;
}

