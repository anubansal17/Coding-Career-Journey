package com.geeksforgeeks.graphs;

import java.util.ArrayList;

public class CountPaths {

    static int countPaths(ArrayList<ArrayList<Integer>> g, int s, int d) {

        if(s == d) return 1;

        ArrayList<Integer> op = new ArrayList<>();
        int[] visited = new int[g.size()];

        visited[s] = 1;
        return dfsUtil(g, visited, s,d);

    }


    static int dfsUtil(ArrayList<ArrayList<Integer>> g, int[] visited, int vertex,int dest){
        int count = 0;
        for(Integer i : g.get(vertex)){
                if(i == dest) {
                    count++;
                }
                visited[i] = 1;
                count+=dfsUtil(g, visited, i, dest);
        }
        return count;
    }
}

