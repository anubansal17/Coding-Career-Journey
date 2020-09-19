package com.geeksforgeeks.graphs;

import java.util.ArrayList;

public class XShapes {
    public static int Shape(String []arr,int N,int M)
    {
        //Your code here
        // Your code here
        int count = 0 ;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(arr[i].charAt(j) == 'X'){
                    count++;
                    dfs(arr, i, j,N,M);
                }
            }
        }
        return count;
    }



    static void dfs(String[] arr, int i, int j,int n, int m){
        if(i<0 || i>= n || j<0 || j>= m) return;
        if(arr[i].charAt(j)  == 'O' || arr[i].charAt(j)  == 'Y') return;
        StringBuilder sb = new StringBuilder(arr[i]);

        sb.setCharAt(j,'Y');
        arr[i] = sb.toString();

        dfs(arr, i, j+1,n,m);
        dfs(arr, i, j-1,n,m);
        dfs(arr, i+1, j,n,m);
        dfs(arr, i-1, j,n,m);


    }
}
