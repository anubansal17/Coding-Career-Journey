# Standard Concepts
1. Databases
2. [ACID](https://www.geeksforgeeks.org/acid-properties-in-dbms/)</br>
3. Relational Database
4. [Normalization](https://www.geeksforgeeks.org/normal-forms-in-dbms/)</br>
5. Indexes - Why? How they work? What are the side effects?
  - Indexes are used to quickly locate data without having to search every row in a database table every time a database table is accessed. Indexes can be created using one or more columns of a database table, providing the basis for both rapid random lookups.</br>
  - Side effects:
    - Extra memory is needed for the indexing data structure
    - Lookup time for index table
    - Updates on the indexed table become slower because also the indexing structure need to be updated
  - Working:
    - The structure that is used to store a database index is called a B+ Tree. In a B+ Tree, the key values are separated into many smaller piles. As the name implies, the piles, technically called nodes, are connected in a tree-like fashion.
    - [Diff b/w B tree and B+ tree](https://www.softwaretestinghelp.com/b-tree-data-structure-cpp/#:~:text=The%20difference%20in%20B%2B%20tree,in%20a%20linked%20list%20fashion)</br>
    - In B+ trees, we have records only in leaf nodes and not in internal nodes
6. Transactions: A transaction can be defined as a group of tasks. A single task is the minimum processing unit which cannot be divided further.</br>
   A transaction in a database system must maintain Atomicity, Consistency, Isolation, and Durability − commonly known as ACID properties.
   
