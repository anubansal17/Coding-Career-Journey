# Maps
- Key Value Pairs</br>
- Implemented using BSTs at the back-end</br>
- For its traversal, iterator is used</br>
- for(it = map.begin();it!=map.end();it++)
- If we need to find if some key is present in the map or not, we have find function</br>
  it = map.find()</br>
  if key is found, we can print it using it->first</br>
  else value of it will be equal to it->end</br>
- In c++ map, keys are always stored in sorted order</br>
- For ordered maps:</br>
- To create a map, it will take O(nlogn) time</br>
- To insert any element, it will take O(logn) time and for n elements, it will take O(nlogn) time</br>
- To find any element, it will also take O(logn) time</br>
- These can't store duplicate keys
- For unordered maps: </br>
- O(1) time
- For multi maps: </br>
- We can store duplicate entries
