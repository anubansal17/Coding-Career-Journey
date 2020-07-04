// https://practice.geeksforgeeks.org/problems/sort-a-stack/1/
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
void insert(stack <int> &s, int temp) {
    // Base condition: If stack is empty or last element in stack is lesser than temp,
    // considering stack s with n-1 elements is already sorted
    if (s.size() == 0 or s.top() <= temp) {
        s.push(temp);
        return;
    }
    
    // Hypothesis
    int val = s.top();
    // Poping out the last element and storing it in backup
    s.pop();
    // Calling the insert function to insert temp
    insert(s, temp);
    // Induction
    s.push(val);
}
/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
    // base condition: if stack has only one element
   if(s.size() == 1) {
       return;
   }
   // Storing the top element, so that it can pushed to the sorted stack afterwards
   int temp = s.top();
   s.pop();
   // Sorting the stack of 1 lesser size, removing the last element
   sort();
   // After sorting the all the remaining elements in stack, insert the last removed element at its correct position
   insert(s, temp);
}
