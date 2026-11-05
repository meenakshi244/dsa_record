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
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
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
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else if (pos == 1)
    {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
    else
    {
        temp = head;
        for (i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
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
        if (head->next == head)
        {
            head = NULL;
        }
        else
        {
            prev = head;
            while (prev->next != head)
                prev = prev->next;
            head = head->next;
            prev->next = head;
        }
        free(temp);
    }
    else
    {
        temp = head;
        for (i = 1; i < pos && temp->next != head; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        if (i != pos)
        {
            printf("Invalid position");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
}
void reverse()
{
    struct node *prev, *current, *next;
    if (head == NULL || head->next == head)
        return;
    prev = head;
    current = head->next;
    while (current != head)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = prev;
    head = prev;
}
void concatenate()
{
    struct node *head2, *newnode;
    struct node *temp1, *temp2;
    int n, i;
    head2 = NULL;
    printf("Enter number of nodes in second list: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        if (head2 == NULL)
        {
            head2 = newnode;
            newnode->next = head2;
        }
        else
        {
            temp2 = head2;
            while (temp2->next != head2)
                temp2 = temp2->next;
            temp2->next = newnode;
            newnode->next = head2;
        }
    }
    if (head == NULL)
        head = head2;
    else if (head2 != NULL)
    {
        temp1 = head;
        while (temp1->next != head)
            temp1 = temp1->next;
        temp2 = head2;
        while (temp2->next != head2)
            temp2 = temp2->next;
        temp1->next = head2;
        temp2->next = head;
    }
}
void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD)");
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
