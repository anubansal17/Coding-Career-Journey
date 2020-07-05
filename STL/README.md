# Maps
- Key Value Pairs</br>
- Implemented using BSTs at the back-end</br>
- We can also have vectors as a value in maps, incase we need to store different values corresponding to same key</br>
- Ordered maps are sorted according to their keys</br>
- For its traversal, iterator is used</br>
- for(it = map.begin();it!=map.end();it++)
- If we need to find if some key is present in the map or not, we have find function
  - it = map.find()
  - if key is found, we can print it using it->first</br>
  - else value of it will be equal to it->end</br>
- In c++ map, keys are always stored in sorted order</br>
- For ordered maps:
  - To create a map, it will take O(nlogn) time</br>
  - To insert any element, it will take O(logn) time and for n elements, it will take O(nlogn) time</br>
  - To find any element, it will also take O(logn) time</br>
  - These can't store duplicate keys
- For unordered maps: </br>
  - O(1) time
- For multi maps: </br>
  - We can store duplicate entries
  
  # Queues
  - FIFO
  - Declaration syntax: queue<data_type>q
  - Operations: q.front(), q.pop(), q.push(), q.empty(), q.clear()
  
  # Stacks
  - LIFO
  - Declaration syntax: stack<data_type>s
  - Operations: s.top(), s.push(), s.pop(), s.empty(), s.clear()
  
  # Priority Queues
  - priority_queue<DT, vector<DT> > pq_name;(Max heap)
  - priority_queue<DT, vector<DT>, greater<DT> > pq_name;(Min heap)
  - Min heap will give the minimum element present in O(logn) time and same in the case of max heap
  - Elements in min heap and max heap are not stored in sorted order but root of in the heap contains the minimum and maximum element respectively
  - Complexity for finding the top element in priority_queue - O(logn)
  - Operations - pq.push(x), pq.top(), pq.empty(), pq.pop()
  
  # Pair
  
  
