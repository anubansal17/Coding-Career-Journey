package com.geeksforgeeks.graphs;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class LevelofNode {
    static int levels(ArrayList<ArrayList<Integer>> g, int x, int in)
    {
        // add your code here
        if(x==in) return 0;
        Queue<Integer> que = new LinkedList<Integer>();
        HashMap<Integer, Boolean> visited = new HashMap<Integer, Boolean>();
        ArrayList<Integer> op = new ArrayList<Integer>();

        for(int i = 0 ; i < g.size() ; i++){
            visited.put(i, false);
        }

        visited.put(x,true);
        que.add(x);
        op.add(x);
        int level = 0;

        while(true){
            int size = que.size();
            level++;
            while(size>0){
                ArrayList<Integer> lst = g.get(que.poll());

                for(Integer i : lst){
                    if(!visited.get(i)){
                        if(i == in) return level;
                        que.add(i);
                        visited.put(i,true);
                        op.add(i);
                    }
                }
                size--;
            }
            if(que.size() == 0) break;
        }

        return level;
    }
}
