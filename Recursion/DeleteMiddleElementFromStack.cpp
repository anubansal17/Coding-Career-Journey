// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
void solve(stack <int> &s, int middle) {
    
    // Base Condition: If we reaches the middle position, i.e. middle becomes 1
    if (middle == 1){
        s.pop();
    }
    int val = s.top();
    s.pop();
    solve(s,middle-1);
    s.push(val);
}
stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
{
    // Base condition: If size of stack is 1
    if(sizeOfStack == 1) {
        s.pop();
        return s;
    }
    int middle = sizeOfStack/2 + 1;
    // Recursive function to delete the middle element
    solve(s, middle);
    return s;
}
