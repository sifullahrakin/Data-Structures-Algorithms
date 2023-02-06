#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
    int number;
    struct linked_list *next;
};

typedef struct linked_list node;

node *head=NULL, *last=NULL;

void create_linked_list()
{
    int val;
    while(1)
    {
        printf("Input a number. (Enter -1 to exit)\n");
        scanf("%d", &val);

        if(val==-1)
            break;
        insert_at_last(val);
    }
}

void insert_at_last(int value)
{
    node *temp_node;
    temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    temp_node->next=NULL;

    //For the 1st element
    if(head==NULL)
    {
        head=temp_node;
        last=temp_node;
    }
    else
    {
        last->next=temp_node;
        last=temp_node;
    }
}

void print_linked_list()
{
    printf("\nYour full linked list is\n");

    node *myList;
    myList = head;

    while(myList!=NULL)
    {
        printf("%d ", myList->number);
        myList = myList->next;
    }
    puts("");
}

int main()
{
    int key, value;

    printf("Create Linked List\n");
    create_linked_list();
    print_linked_list();

    //Insert value at last position to existing Linked List
    printf("\nInsert new item at last\n");
    scanf("%d", &value);
    insert_at_last(value);
    print_linked_list();

    return 0;

}

