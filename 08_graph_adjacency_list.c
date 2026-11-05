#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct node
{
    int vertex;
    struct node *next;
};

struct node *adj[MAX];
int exists[MAX];

void addEdge(int u, int v)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    if (adj[u] == NULL)
        adj[u] = newnode;
    else
    {
        temp = adj[u];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void removeEdge(int u, int v)
{
    struct node *temp, *prev = NULL;
    temp = adj[u];
    while (temp != NULL && temp->vertex != v)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    if (prev == NULL)
        adj[u] = temp->next;
    else
        prev->next = temp->next;
    free(temp);
}

void insertVertex()
{
    int v;
    printf("Enter vertex number (0-%d): ", MAX - 1);
    scanf("%d", &v);
    if (v < 0 || v >= MAX)
        printf("Invalid vertex\n");
    else if (exists[v])
        printf("Vertex already exists\n");
    else
    {
        exists[v] = 1;
        adj[v] = NULL;
        printf("Vertex %d inserted\n", v);
    }
}

void insertEdge()
{
    int u, v;
    printf("Enter edge (u v): ");
    scanf("%d %d", &u, &v);
    if (u < 0 || u >= MAX || v < 0 || v >= MAX || !exists[u] || !exists[v])
        printf("Both vertices must exist\n");
    else
    {
        addEdge(u, v);
        addEdge(v, u);
        printf("Edge inserted\n");
    }
}

void deleteEdge()
{
    int u, v;
    printf("Enter edge to delete (u v): ");
    scanf("%d %d", &u, &v);
    if (u < 0 || u >= MAX || v < 0 || v >= MAX || !exists[u] || !exists[v])
        printf("Both vertices must exist\n");
    else
    {
        removeEdge(u, v);
        removeEdge(v, u);
        printf("Edge deleted\n");
    }
}

void deleteVertex()
{
    int v, i;
    struct node *temp, *next;
    printf("Enter vertex to delete: ");
    scanf("%d", &v);
    if (v < 0 || v >= MAX || !exists[v])
    {
        printf("Vertex does not exist\n");
        return;
    }
    temp = adj[v];
    while (temp != NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    adj[v] = NULL;
    exists[v] = 0;
    for (i = 0; i < MAX; i++)
        if (exists[i])
            removeEdge(i, v);
    printf("Vertex %d deleted\n", v);
}

void display()
{
    int i;
    struct node *temp;
    for (i = 0; i < MAX; i++)
    {
        if (exists[i])
        {
            printf("%d -> ", i);
            temp = adj[i];
            while (temp != NULL)
            {
                printf("%d -> ", temp->vertex);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Insert vertex");
        printf("\n2. Insert edge");
        printf("\n3. Delete vertex");
        printf("\n4. Delete edge");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: insertVertex(); break;
        case 2: insertEdge(); break;
        case 3: deleteVertex(); break;
        case 4: deleteEdge(); break;
        case 5: display(); break;
        case 6: exit(0);
        default: printf("Invalid choice");
        }
    }
    return 0;
}
