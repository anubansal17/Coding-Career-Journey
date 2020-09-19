package com.geeksforgeeks.graphs;

import java.util.ArrayList;
import java.util.HashSet;

public class DetectCycleDirectedGraph {
    public static void main(String[] args) {

    }
    static boolean isCyclic(ArrayList<ArrayList<Integer>> g, int N)
    {
        int[] visited = new int[N];


        for(int i = 0 ; i < N ;i++){
            if(visited[i] == 0){
                visited[i] = 1;
                HashSet<Integer> hs = new HashSet<>();
                hs.add(i);
                if(dfsUtil(g, visited, i,hs)) return true;
            }
        }
        return false;

    }

    static boolean dfsUtil(ArrayList<ArrayList<Integer>> g, int[] visited, int vertex,HashSet<Integer> parent){
        for(Integer i : g.get(vertex)){

            if(visited[i] == 1 && parent.contains(i)) return true;
            if(visited[i] == 0){
                visited[i] = 1;
                HashSet<Integer> tmp = new HashSet<>(parent);
                tmp.add(i);
                if(dfsUtil(g, visited, i,tmp)) return true;
            }


        }
        return false;
    }
}
