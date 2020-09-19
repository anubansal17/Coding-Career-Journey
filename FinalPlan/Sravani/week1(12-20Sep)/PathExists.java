package com.geeksforgeeks.graphs;

public class PathExists {

    public static void main(String[] args) {
        int arr[][] ={
            {
                3, 0, 0, 0
            },
            {
                0, 3, 3, 0
            },
            {
                0, 1, 0, 3
            },
            {
                0, 2, 3, 3
            }
        };
            System.out.println(is_possible(arr, arr.length));
    }
    public static int is_possible(int arr[][], int n) {
        for(int i = 0; i< n ; i++){
            for(int j = 0 ; j< n ; j++){
                if(arr[i][j] == 1)
                    return recurUtil(i,j,arr) ? 1:0;
            }
        }
        return 0;
    }

    static boolean recurUtil(int i , int j , int[][] arr){

        if(i<0 || i>= arr.length || j<0 || j>= arr.length) return false;
        if(arr[i][j] == 2) return true;
        if(arr[i][j] == -3 || arr[i][j] == 0 || arr[i][j] == -1) return false;

        arr[i][j] = -1 * arr[i][j];

        return recurUtil(i+1,j,arr) || recurUtil(i,j-1,arr) || recurUtil(i-1,j,arr) || recurUtil(i,j+1,arr);
    }
}
