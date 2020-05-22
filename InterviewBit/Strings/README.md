# Standard Concepts
## Additional concepts
- Sorting a structure on the basis of one of the parameter, i.e., using a comparator
  - Example:
    - struct data{string name;int marks};data a[10]; data is having parameters name and marks
    - if we want to sort the struct on the basis of marks
    - use sort(a, a+n, cmp)
    - cmp function: cmp (data p, data q){
      - return p.marks < q.marks}
