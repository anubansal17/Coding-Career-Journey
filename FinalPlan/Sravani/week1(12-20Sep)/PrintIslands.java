package com.geeksforgeeks.graphs;

import java.util.ArrayList;

public class PrintIslands {
    public static void main(String[] args) {

    }
    static int findIslands(ArrayList<ArrayList<Integer>> arr, int N, int M) {

        // Your code here
        int count = 0 ;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(arr.get(i).get(j) == 1){
                    dfs(arr, i, j,N,M);
                }
            }
        }
        return count;
    }

    static void dfs(ArrayList<ArrayList<Integer>> arr, int i, int j,int n, int m){
        if(i<0 || i>= n || j<0 || j>= m) return;
        if(arr.get(i).get(j) == 0 || arr.get(i).get(j) == -1) return;
        arr.get(i).set(j,-1);

        dfs(arr, i, j+1,n,m);
        dfs(arr, i, j-1,n,m);
        dfs(arr, i+1, j,n,m);
        dfs(arr, i+1, j-1,n,m);
        dfs(arr, i+1, j+1,n,m);
        dfs(arr, i-1, j,n,m);
        dfs(arr, i-1, j+1,n,m);
        dfs(arr, i-1, j-1,n,m);

    }
}
