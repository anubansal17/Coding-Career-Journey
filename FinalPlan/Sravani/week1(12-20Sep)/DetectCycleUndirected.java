package com.geeksforgeeks.graphs;

import java.util.ArrayList;

public class DetectCycleUndirected {
    public static void main(String[] args) {

    }

    static boolean isCyclic(ArrayList<ArrayList<Integer>> g, int N)
    {
        int[] visited = new int[N];


        for(int i = 0 ; i < N ;i++){
            if(visited[i] == 0){
                visited[i] = 1;
                if(dfsUtil(g, visited, i,i)) return true;
            }
        }
        return false;

    }

    static boolean dfsUtil(ArrayList<ArrayList<Integer>> g, int[] visited, int vertex,int parent){
        for(Integer i : g.get(vertex)){
            if(i!= parent){
                if(visited[i] == 1) return true;
                if(visited[i] == 0){
                    visited[i] = 1;

                    if(dfsUtil(g, visited, i,vertex)) return true;
                }
            }

        }
        return false;
    }
}
