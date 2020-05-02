# Basics
## Few standard problems:
- To find the first occurence of any element in the array:
  - Implement the basic binary search algo then instead of returning in the case of number searched is equal to mid,
  - set ans = mid and right = mid - 1 and continue with algo
- To find the last occurence of any element in the array:
  - Similar to above but set ans = mid and left = mid+1 instead of setting right = mid - 1
- To calculate the count of the number of occurences if any element:
  - Calculate the first occurence and last occurence and then return the answer as last_occurence_index - first_occurence_index + 1
