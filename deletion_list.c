
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;


void create()
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}


void delete_begin()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);

        printf("Node deleted from beginning\n");
    }
}


void delete_end()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;

        printf("Node deleted from end\n");
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);

        printf("Node deleted from end\n");
    }
}


void delete_pos()
{
    struct node *temp, *prev;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position\n");
    }
    else if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);

        printf("Node deleted successfully\n");
    }
    else
    {
        temp = head;

        for (i = 1; i < pos && temp != NULL; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("Invalid position\n");
        }
        else
        {
            prev->next = temp->next;
            free(temp);

            printf("Node deleted successfully\n");
        }
    }
}


void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


int main()
{
    int choice;

    create();

    while (1)
    {
        printf("\n--- LINKED LIST DELETION ---\n");
        printf("1. Delete at Beginning ");
        printf("2. Delete at End ");
        printf("3. Delete at Specific Position ");
        printf("4. Display ");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                delete_begin();
                break;

            case 2:
                delete_end();
                break;

            case 3:
                delete_pos();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
