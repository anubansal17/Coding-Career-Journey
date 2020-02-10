#include <bits/stdc++.h> 
using namespace std; 
  
int remainder(string str) 
{
    int len = str.length(); 
  
    int num, rem = 0;
    for (int i = 0; i < len; i++) { 
        num = rem * 10 + (str[i] - '0'); 
        rem = num % 11; 
    } 
  
    return rem; 
} 
int main() 
{ 
    string str = "3435346456547566345436457867978"; 
    cout << remainder(str); 
    return 0; 
} 
