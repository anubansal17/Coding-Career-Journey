package com.geeksforgeeks.backtracking;

import java.util.List;

public class GraphColoring {

    public static void main(String[] args) {

    }
    public static boolean graphColoring(List<Integer>[] g, int[] color, int vertex, int C) {

        if(vertex == g.length) return true;
        for(int i = 1 ; i <= C; i++){
            if(isSafe(g,color,vertex ,i)){
                color[vertex] = i;
                if(graphColoring(g, color, vertex+1, C))
                    return true;
                else color[vertex] = 0;
            }
        }
        return false;
    }

    public static boolean isSafe(List<Integer>[] g, int[] color, int vertex, int col){

        for(Integer adj : g[vertex]){

            if (color[adj] == col) return false;

        }
        return true;
    }
}
