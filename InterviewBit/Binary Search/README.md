# Basics
## Few standard problems:
- To find the first occurence of any element in the array:
  - Implement the basic binary search algo then instead of returning in the case of number searched is equal to mid,
  - set ans = mid and right = mid - 1 and continue with algo
- To find the last occurence of any element in the array:
  - Similar to above but set ans = mid and left = mid+1 instead of setting right = mid - 1
- To calculate the count of the number of occurences if any element:
  - Calculate the first occurence and last occurence and then return the answer as last_occurence_index - first_occurence_index + 1
- To find number of rotations in a rotated sorted array(circularly sorted array)
  - Given: l = 0, r = n-1, array A of size n and array doesn't contain any duplicates
  - Answer would be index of minimum element in the array
  - Here, minimum element follows the property that both the elements at its left and right will be greater than this element
  - next = (mid + 1)%n and prev = (mid - 1)%n
  - Case1: If A[l] <= A[r], it implies the array is already sorted so the answer would be l.
  - Case2: If A[mid] <= A[next] and A[mid] <= A[prev] then return mid
  - Case3: If A[mid] <= A[r] then make r = mid - 1
  - Case4: If A[mid] >= A[l] then make l = mid + 1
