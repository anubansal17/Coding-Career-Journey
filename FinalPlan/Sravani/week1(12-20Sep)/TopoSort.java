package com.geeksforgeeks.graphs;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Stack;

public class TopoSort {
    static int[] topoSort(ArrayList<ArrayList<Integer>> adj, int N) {
        int[] visited = new int[N];
        Stack<Integer> stack = new Stack<Integer>();

        for(int i = 0 ; i < N ;i++){
            if(visited[i] == 0){
                topoUtil(adj, visited, i,stack);
            }
        }
        int op[] = new int[stack.size()];
        int i = 0;
        while (stack.empty()==false)
            op[i++] = stack.pop();
        return op;
    }
    static void topoUtil(ArrayList<ArrayList<Integer>> g, int[] visited, int vertex ,Stack<Integer> stack){
        for(Integer i : g.get(vertex)){
            if(visited[i] == 0){
                visited[i] = 1;
                topoUtil(g, visited, i, stack);
            }
        }
        stack.push(vertex);
    }
}
