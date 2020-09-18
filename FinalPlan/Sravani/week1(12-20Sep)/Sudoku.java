package com.geeksforgeeks.backtracking;

public class Sudoku {
    public static void main(String[] args) {
        int grid[][] = new int[][]{
            {3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0} };

        System.out.println(SolveSudoku(grid));
    }

    static boolean SolveSudoku(int grid[][])
    {
        int i = -1;
        int j = -1;
        boolean isEmpty = true;
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (grid[row][col] == 0) {
                    i = row;
                    j = col;

                    // we still have some remaining
                    // missing values in Sudoku
                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty) {
                break;
            }
        }


        if (isEmpty) {
            return true;
        }

        for(int val = 1; val<=9 ; val++){
//            grid[i][j] = val;

            if(isSafe(i,j,val, grid)){
                grid[i][j] = val;
                if(SolveSudoku(grid)){
//                    System.out.println(i+ " "+j +" "+val);
                    return true;
                }
                grid[i][j] = 0;


            }

        }
        return false;


    }



    static boolean isSafe(int i, int j, int val, int[][] grid){
        for(int loc = 0;loc < 9 ; loc++){
            if(grid[i][loc] == val || grid[loc][j] == val) return false;
        }
        int start_i = i/3;
        int start_j = j/3;
        start_i *= 3;
        start_j *= 3;
        int end_i = start_i+2;
        int end_j = start_j+2;
        System.out.println(start_i+" "+start_j+"   "+end_i+" "+end_j);
        for(int row = start_i ; row <end_i ; row++ ){
            for(int col = start_j ; col < end_j ; col++){
                if(grid[row][col] == val) return false;
            }
        }
        return true;
    }
}
