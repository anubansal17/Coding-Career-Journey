# Goal - Making it to Prod Based
## Week 1 (Graphs+Recursion+Backtracking+DSU) & Week 2 (Binary Search and Greedy Algo)
12 Sept - 20 Sept
### Anu Learnings

#### 12 Sept
1. [Implement Disjoint Set (data structure for union-find), without any optimization](https://practice.geeksforgeeks.org/problems/disjoint-set-union-find/1)
2. Implementation for storing graph in adjacency list
3. BFS Implementation

#### 13 Sept
1. DFS Implementation
2. DSU Implementation - Ranks + Path Compression
3. BFS, DFS 
Practice questions: Pending</br>
  (https://www.spoj.com/problems/CAM5/)</br>
  (https://www.spoj.com/problems/PT07Y/)</br>
  (https://www.spoj.com/problems/PT07Z/)</br>
  (https://www.spoj.com/problems/PPATH/)</br>
  (https://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/</br>

#### 16 Sept
1. DSU Applications - Connected Components, Detect a cycle, Minimum spanning tree
2. [DSU Practice Questions](https://www.hackerearth.com/challenges/competitive/code-monk-disjoint-set-union/problems/) - Pending
3. Minimum Spanning Tree: Kruskal, Prims
  Algo:
  a) Sort all the edges according to asc order of weights</br>
  b) Apply DSU algo and calculate total weight</br>
 
### 20 Sept
1. Djikstra Algo Implementation
2. [The Turtle´s Shortest Path](https://www.spoj.com/problems/TSHPATH/)
3. [https://www.spoj.com/problems/CCHESS/](https://www.spoj.com/problems/CCHESS/)
4. [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

### 22 Sept
1. DFS Applications
  1. Detecting a cycle: For every visited vertex 'v', if there is an adjacent 'u' such that u is already visited and u is nit a parent of v, then there is a cycle in graph
  2. Topological Sort: For a DAG G = (V, E) is a linear ordering of all its vertices such that if G contains an edge (u,v) the u appears before v in ordering(Practical application- Job scheduling). Use DFS traversal using a temporary stack
  3. Strongly connected component: A directed graph is strongly connected if there is a path between all pair of vertices.
      - Kosaraju's Algo - uses two passes of depth first search
      - Tarjan's Algo - uses a single pass of depth first search
  4. Path finding: To find a path between two given vertices
      - Call DFS(G,u) with u as the start vertex
      - Use a stack S to keep track of path between the start vertex and the current vertex
      - As soon as the destination vertex v is encountered, return the path as the contents of the stack
  5. Check if the graph is bipartite or not: Graph whose vertices can be divided into two independent sets, i.e. there is no edge that connects vertices of same set
      - Use a two coloring scheme, start with a vertex and give it a color
      - Run depth-first search from this vertex
      - For each new vertex, color it opposite it's parents
      - Check for edges that it doesn't link two vertices of the same color
  6. Puzzles problem: maze related problems, obstacles in a matrix
2. BFS Applications
  - 1. Shortest Path in a graph: 

## Trees
### 28 Sept
1. [Tree Traversals](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/)
  - Inorder, Preorder, Postorder
  1. InOrder applications: In BST, it gives nodes in non-decreasing order
  2. PreOrder applications: To create a copy of tree, To get prefix expression of an expression tree(Polish notation)
  3. PostOrder applications: To delete a tree, to get the postfix expression of an expression(Reverse Polish notation)
2. [Calculate Size of a tree](https://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/)
3. [Check if two trees are identical or not](https://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/)
4. [Find Height of a tree](https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/)
5. [Delete a tree](https://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/)
6. [Convert a binary tree into its mirror tree](https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/)
7. [Given two traversal sequences, construct binary tree](https://www.geeksforgeeks.org/if-you-are-given-two-traversal-sequences-can-you-construct-the-binary-tree/)
8. 
 
