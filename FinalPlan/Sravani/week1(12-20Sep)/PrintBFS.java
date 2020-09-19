package com.geeksforgeeks.graphs;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class PrintBFS {
    static ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> g, int N) {
        // add your code here
        Queue<Integer> que = new LinkedList<Integer>();
        HashMap<Integer, Boolean> visited = new HashMap<Integer, Boolean>();
        ArrayList<Integer> op = new ArrayList<Integer>();

        for(int i = 0 ; i < g.size() ; i++){
            visited.put(i, false);
        }

        visited.put(N,true);
        que.add(N);
        op.add(N);

        while(que.size() != 0){
            ArrayList<Integer> lst = g.get(que.poll());

            for(Integer i : lst){
                if(!visited.get(i)){
                    que.add(i);
                    visited.put(i,true);
                    op.add(i);
                }
            }
        }
        return op;
    }
}
