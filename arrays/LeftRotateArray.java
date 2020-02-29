/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

public class RotateArrays{
  static void reverseArray(int arr[], int start, int end) {
       int temp;
       while (start < end && end != 0) { 
            temp = arr[start]; 
            arr[start] = arr[end]; 
            arr[end] = temp; 
            start++; 
            end--; 
        } 
   }
   static void leftRotate(int arr[], int d) {
    int n = arr.length;
    if(d == 0)
        return;
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
   }
   
   static void printArray(int arr[]) {
       for(int i=0; i<arr.length; i++)
       {
           System.out.print(arr[i] + " ");
       }
       	System.out.println('');
   }
	public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();
		for (int i=0; i<T; i++) {
		    int N;
		    N = sc.nextInt();
		    int arr[] = new int[N];
		    for (int j=0; j<N; j++)
		    {
		        arr[j] = sc.nextInt();
		    }
		    int d = sc.nextInt();
            leftRotate(arr, d);
            printArray(arr); 
		    
		}
	
	}
}
