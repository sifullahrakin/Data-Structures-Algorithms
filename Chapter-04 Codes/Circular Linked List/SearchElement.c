#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};
void createList(struct node **head, int n);
void displayList(struct node *head);
int  search(struct node *head, int key);

int main()
{
    int n, choice, index;
    struct node *head = NULL;

    while(choice != 0)
    {
        printf("--------------------------------------------\n");
        printf("        CIRCULAR LINKED LIST PROGRAM        \n");
        printf("--------------------------------------------\n");
        printf("1. Create List\n");
        printf("2. Display list\n");
        printf("3. Search element\n");
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
		printf("Enter element to search: ");
		scanf("%d", &n);
		index = search(head, n);

		if (index == -1)
		  printf("%d not found in list.\n", n);
		else 
                  printf("%d found at %d position.\n", n, (index + 1));
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
        printf("\n\n\n\n\n");
    }
    return 0;
}
int search(struct node *head, int key)
{
    int index = 0;
    struct node *current = head;

    do 
    {
		if (current == NULL)
			return;
		
		if (current->data == key)
			return index;

        current = current->next;
		index++;
    } while (current != head);

    return -1;
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