#include <stdio.h>
#define MAX 20
#define INF 9999

void printPath(int parent[], int v)
{
    if (parent[v] == -1)
    {
        printf("%d", v);
        return;
    }
    printPath(parent, parent[v]);
    printf(" -> %d", v);
}

int main()
{
    int g[MAX][MAX], dist[MAX], visited[MAX], parent[MAX];
    int n, i, j, src, count, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
            if (g[i][j] == 0 && i != j)
                g[i][j] = INF;
        }
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (count = 0; count < n - 1; count++)
    {
        min = INF;
        u = -1;
        for (i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        if (u == -1)
            break;
        visited[u] = 1;
        for (j = 0; j < n; j++)
            if (!visited[j] && g[u][j] != INF && dist[u] + g[u][j] < dist[j])
            {
                dist[j] = dist[u] + g[u][j];
                parent[j] = u;
            }
    }

    printf("\nVertex\tDistance\tPath\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", i);
        if (dist[i] == INF)
            printf("INF\t\tNo path\n");
        else
        {
            printf("%d\t\t", dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
    return 0;
}
