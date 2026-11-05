#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct node
{
    int vertex;
    struct node *next;
};

struct node *adj[MAX];

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

void bfs(int start, int n)
{
    int queue[MAX], visited[MAX] = {0};
    int front = 0, rear = 0, u;
    struct node *temp;

    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS traversal: ");
    while (front < rear)
    {
        u = queue[front++];
        printf("%d ", u);
        temp = adj[u];
        while (temp != NULL)
        {
            if (!visited[temp->vertex])
            {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int n, e, i, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (i = 0; i < n; i++)
        adj[i] = NULL;
    printf("Enter edges (u v), vertices are 0 to %d:\n", n - 1);
    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    bfs(start, n);
    return 0;
}
