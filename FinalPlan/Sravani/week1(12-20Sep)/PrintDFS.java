package com.geeksforgeeks.graphs;

import java.util.ArrayList;

public class PrintDFS {
    public static void main(String[] args) {

    }

    static ArrayList<Integer> dfs(ArrayList<ArrayList<Integer>> g, int N)
    {
        ArrayList<Integer> op = new ArrayList<>();
        int[] visited = new int[N];
        op.add(0);
        visited[0] = 1;
        dfsUtil(g, visited, 0, op);
        return op;
    }

    static void dfsUtil(ArrayList<ArrayList<Integer>> g, int[] visited, int vertex , ArrayList<Integer> op){
        for(Integer i : g.get(vertex)){
            if(visited[i] == 0){
                visited[i] = 1;
                op.add(i);
                dfsUtil(g, visited, i, op);
            }
        }
    }

}
