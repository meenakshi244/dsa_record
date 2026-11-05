#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *insertNode(struct node *r, int x)
{
    if (r == NULL)
    {
        r = (struct node *)malloc(sizeof(struct node));
        r->data = x;
        r->left = NULL;
        r->right = NULL;
    }
    else if (x < r->data)
        r->left = insertNode(r->left, x);
    else if (x > r->data)
        r->right = insertNode(r->right, x);
    else
        printf("Duplicate value %d ignored\n", x);
    return r;
}

void create()
{
    int n, i, x;
    root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &x);
        root = insertNode(root, x);
    }
}

void inorder(struct node *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(struct node *r)
{
    if (r != NULL)
    {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node *r)
{
    if (r != NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

void search()
{
    int key;
    struct node *temp = root;
    printf("Enter element to search: ");
    scanf("%d", &key);
    while (temp != NULL)
    {
        if (key == temp->data)
        {
            printf("Element %d found in the tree\n", key);
            return;
        }
        else if (key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    printf("Element not found\n");
}

int main()
{
    int choice, x;
    while (1)
    {
        printf("\n\n1. Create");
        printf("\n2. Insert");
        printf("\n3. Inorder");
        printf("\n4. Preorder");
        printf("\n5. Postorder");
        printf("\n6. Search");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: create(); break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &x);
            root = insertNode(root, x);
            break;
        case 3: printf("Inorder: ");   inorder(root);   break;
        case 4: printf("Preorder: ");  preorder(root);  break;
        case 5: printf("Postorder: "); postorder(root); break;
        case 6: search(); break;
        case 7: exit(0);
        default: printf("Invalid choice");
        }
    }
    return 0;
}
