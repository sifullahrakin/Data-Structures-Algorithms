#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

void createList(struct node **head, int n);
void displayList(struct node *head);
void reverseList(struct node **head);


int main()
{
    int n, choice;

    struct node *head = NULL;

    while(choice != 0)
    {
        printf("--------------------------------------------\n");
        printf("        CIRCULAR LINKED LIST PROGRAM        \n");
        printf("--------------------------------------------\n");
        printf("1. Create List\n");
        printf("2. Display list\n");
        printf("3. Reverse list\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter total node to create: ");
                scanf("%d", &n);
                createList(&head, n);
                break;
            
            case 2:
                displayList(head);
                getchar(); 
                getchar(); 
                break;
            
            case 3:
                reverseList(&head);
                printf("List reversed.\n");
				getchar(); 
                getchar();
                break;

            case 0:
                printf("Exiting from application");
                exit(0);
                break;

            default:
                printf("Error! Invalid choice. Please choose between 0-3");
        }

        printf("\n\n");
    }

    return 0;
}

void reverseList(struct node **head) 
{
    struct node *prev, *cur, *next, *last;

    if (*head == NULL)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }

    last = *head;

    prev  = *head;
    cur   = (*head)->next;
    *head = (*head)->next;

    while (*head != last)
    {
        *head = (*head)->next;
        cur->next = prev;

        prev = cur;
        cur  = *head;
    }
    cur->next = prev;
    *head = prev;
}

void createList(struct node **head, int n)
{
    int i, data;
    struct node *prevNode, *newNode;

    prevNode = NULL;
    newNode  = NULL;

    for(i=1; i<=n; i++)
    {
        newNode = (struct node *) malloc(sizeof(struct node));

        printf("Enter data of %d node: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (prevNode != NULL)
            prevNode->next = newNode;

        prevNode = newNode;

        if (*head == NULL)
            *head = newNode;
    }
    prevNode->next = *head;
    printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
}
void displayList(struct node *head)
{
    struct node *current;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    current = head;
    printf("DATA IN THE LIST:\n");

    do 
    {
        printf("Data %d = %d\n", n++, current->data);

        current = current->next;
    } while (current != head);
}