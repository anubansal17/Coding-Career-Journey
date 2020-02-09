//Stack1 starts form leftmost corner of the array and stack2 starts from rightmost corner of the array
// Both the stacks grow in opposite direction and to check overflow we just need to check space between top elements of the two stacks
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};

void twoStacks :: push1(int x)
{
if(top1< top2-1)
{
    top1++;
    arr[top1] = x;
    
}
else 
{
    cout<<"Stack Overflow";
    exit(1);
}
}
   
/* The method push to push element into the stack 2*/
void twoStacks ::push2(int x)
{
if(top1<top2-1)
{
    top2--;
    arr[top2] = x;
}
else
{
    cout<<"Stack Overflow";
    exit(1);
}

}
   
/* The method pop to pop element from the stack 1 */

int twoStacks :: pop1() 
   { 
       if (top1 >= 0 ) 
       { 
          int x = arr[top1]; 
          top1--; 
          return x; 
       } 
       else
       {
           return -1;
       } 
   } 
  
   // Method to pop an element from second stack 
int twoStacks :: pop2() 
   { 
       if (top2 < size) 
       { 
          int x = arr[top2]; 
          top2++; 
          return x; 
       } 
       else
       { 
           
           return -1; 
       } 
   }
