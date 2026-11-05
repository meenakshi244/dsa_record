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
    head = NULL;
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
            head = newnode;
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}
void insert()
{
    struct node *newnode, *temp;
    int pos, i;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        for (i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if (temp == NULL)
            printf("Invalid position");
        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}
void deleteNode()
{
    struct node *temp, *prev;
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
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
            printf("Invalid position");
        else
        {
            prev->next = temp->next;
            free(temp);
        }
    }
}
void reverse()
{
    struct node *prev, *current, *next;
    prev = NULL;
    current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void concatenate()
{
    struct node *head2, *newnode, *temp;
    int n, i;
    head2 = NULL;
    printf("Enter number of nodes in second list: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head2 == NULL)
            head2 = newnode;
        else
        {
            temp = head2;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    if (head == NULL)
        head = head2;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head2;
    }
}
void display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n\n1. Create");
        printf("\n2. Insert");
        printf("\n3. Delete");
        printf("\n4. Reverse");
        printf("\n5. Concatenate");
        printf("\n6. Display");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: create(); break;
        case 2: insert(); break;
        case 3: deleteNode(); break;
        case 4: reverse(); break;
        case 5: concatenate(); break;
        case 6: display(); break;
        case 7: exit(0);
        default: printf("Invalid choice");
        }
    }
}
