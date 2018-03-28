#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head;

void createList(int n);
void deleteLastNode();
void displayList();


int main()
{
    int n, choice;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    printf("\nPress 1 to delete last node: ");
    scanf("%d", &choice);

    if(choice == 1)
        deleteLastNode();

    printf("\nData in the list \n");
    displayList();

    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data;
                newNode->next = NULL;

                temp->next = newNode;
                temp = temp->next;
            }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
}

void deleteLastNode()
{
    struct node *toDelete, *temp;

    temp=head;
    toDelete=head;

        while(toDelete->next != NULL)
        {
            temp= toDelete;
            toDelete=toDelete->next;
        }
        if(toDelete==head)
        {
           head=head->next;
        }
         temp->next=NULL;

        printf("\nData deleted = %d\n", toDelete->data);

        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
}

void displayList()
{
    struct node *temp;

        temp = head;
        while(temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("NULL");
}
