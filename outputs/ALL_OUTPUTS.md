# Sample Outputs (Programs 7-11)

Compiled with gcc and run; the output below is real.

## 7. Binary Search Tree

```


1. Create
2. Insert
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 1
Enter number of nodes: 7
Enter data: 50
Enter data: 30
Enter data: 70
Enter data: 20
Enter data: 40
Enter data: 60
Enter data: 80


1. Create
2. Insert
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 3
Inorder: 20 30 40 50 60 70 80 

1. Create
2. Insert
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 4
Preorder: 50 30 20 40 70 60 80 

1. Create
2. Insert
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 5
Postorder: 20 40 30 60 80 70 50 

1. Create
2. Insert
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 6
Enter element to search: 40
Element 40 found in the tree


1. Create
2. Insert
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 6
Enter element to search: 99
Element not found


1. Create
2. Insert
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 2
Enter data: 65


1. Create
2. Insert
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 3
Inorder: 20 30 40 50 60 65 70 80 

1. Create
2. Insert
3. Inorder
4. Preorder
5. Postorder
6. Search
7. Exit
Enter choice: 7
```

## 8. Graph using Adjacency List (insert/delete)

```

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 1
Enter vertex number (0-19): 0
Vertex 0 inserted

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 1
Enter vertex number (0-19): 1
Vertex 1 inserted

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 1
Enter vertex number (0-19): 2
Vertex 2 inserted

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 1
Enter vertex number (0-19): 3
Vertex 3 inserted

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 2
Enter edge (u v): 0 1
Edge inserted

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 2
Enter edge (u v): 0 2
Edge inserted

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 2
Enter edge (u v): 1 3
Edge inserted

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 2
Enter edge (u v): 2 3
Edge inserted

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 5
0 -> 1 -> 2 -> NULL
1 -> 0 -> 3 -> NULL
2 -> 0 -> 3 -> NULL
3 -> 1 -> 2 -> NULL

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 4
Enter edge to delete (u v): 0 2
Edge deleted

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 5
0 -> 1 -> NULL
1 -> 0 -> 3 -> NULL
2 -> 3 -> NULL
3 -> 1 -> 2 -> NULL

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 3
Enter vertex to delete: 3
Vertex 3 deleted

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 5
0 -> 1 -> NULL
1 -> 0 -> NULL
2 -> NULL

1. Insert vertex
2. Insert edge
3. Delete vertex
4. Delete edge
5. Display
6. Exit
Enter choice: 6
```

## 9. Dijkstra's Shortest Path

```
Enter number of vertices: 5
Enter adjacency matrix (0 for no edge):
0 10 0 30 100
0 0 50 0 0
0 0 0 0 10
0 0 20 0 60
0 0 0 0 0
Enter source vertex (0 to 4): 0

Vertex	Distance	Path
0	0		0
1	10		0 -> 1
2	50		0 -> 3 -> 2
3	30		0 -> 3
4	60		0 -> 3 -> 2 -> 4
```

## 10. Breadth First Search

```
Enter number of vertices: 6
Enter number of edges: 7
Enter edges (u v), vertices are 0 to 5:
0 1
0 2
1 3
2 3
3 4
4 5
2 5
Enter starting vertex: 0
BFS traversal: 0 1 2 3 5 4
```

## 11. Depth First Search

```
Enter number of vertices: 6
Enter number of edges: 7
Enter edges (u v), vertices are 0 to 5:
0 1
0 2
1 3
2 3
3 4
4 5
2 5
Enter starting vertex: 0
DFS traversal: 0 1 3 2 5 4
```
