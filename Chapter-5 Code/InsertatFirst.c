#include<stdio.h>
#include<stdlib.h>

struct node     //make node for linked list using structure
{
    int value;            //value part of node contains the element
    struct node *next;    //the next part of node contains the address of next element of list
};

struct node *head;    //contains the address of first element of linked list

void init()
{
    head=NULL;    //initialize the beginning(head) of list to NULL
}

void insertfirst(int element)   //inserts element in linked list
{
    struct node *New;
    New=(struct node*)malloc(sizeof(struct node));    //New named node declared with size of node declared before
    New->value=element;       //inserts the new element to the value part of node New
    New->next=NULL;           //makes the next part of node New NULL so that no garbage value remains
    New->next=head;         //the address of previously first node, which was stored in head is now assigned to next part of node New
    head=New;              //the address of new first element which is present in node New is assigned to head node
}

//If you want to print the list
void print()
{
    if(head==NULL)    //condition to check whether list is empty
    {
        printf("list is empty\n");
        return;
    }
    struct node *cur=head;
    int count;
    count=0;
    while(cur!=NULL)                  //the loop traverse until it gets any NULL node
    {
        printf("%d->",cur->value);
        count++;                      //counts the number of nodes or elements present in list
        cur=cur->next;                //moves cur pointer to next node to check and get value
    }
    printf("NULL\n");
    printf("number of nodes %d\n",count);
}


int main()
{
     int i,element;

     for(i=1;i<=5;i++){
        printf("enter element to list: ");
        scanf("%d",&element);
        insertfirst(element);
     }
     printf("Inserted at First!\n");
     printf("List is\n");
     print();

    return 0;
}
