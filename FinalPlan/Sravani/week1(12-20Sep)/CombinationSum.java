package com.geeksforgeeks.backtracking;

import java.util.*;

public class CombinationSum {
    public static void main(String[] args) {
        combinationSum(new ArrayList<>(Arrays.asList(7,2,6,5)),16);
    }

    static ArrayList<ArrayList<Integer>> combinationSum(ArrayList<Integer> arr, int n)
    {
        // add your code here
        HashSet<ArrayList<Integer>> op = new HashSet<>();
        Collections.sort(arr);
        solveUtil(arr, n, new ArrayList<Integer>(), op,0);

        ArrayList<ArrayList<Integer>> output = new ArrayList<>(op);
        Collections.sort(output, new Comparator<ArrayList<Integer>>() {
            public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2) {
//                return o1.get(0).compareTo(o2.get(0));
                int oneSize = o1.size();
                int twoSize = o1.size();
                for(int i = 0; i < oneSize; i++)
                {
                    if(i == oneSize || i == twoSize)
                        return oneSize - twoSize;

                    int elementOne = o1.get(i);
                    int elementTwo = o2.get(i);
                    if(elementOne == elementTwo)
                        continue;

                    return Integer.compare(elementOne, elementTwo);
                }
                return -1;
            }
        });

        for(ArrayList<Integer> lst : output){
            for(Integer i:lst){
                System.out.print(i+" ");
            }
            System.out.println();
        }
        return output;
    }


    static void solveUtil(ArrayList<Integer> arr, int n, ArrayList<Integer> curr, HashSet<ArrayList<Integer>> op, int i){
        if(n<0) return;
        if(n==0){
            op.add(new ArrayList<Integer>(curr));
            return;
        }

        for(;i<arr.size()&& n-arr.get(i) >=0 ; i++){
            if(arr.get(i) <= n){
                curr.add(arr.get(i));
                solveUtil(arr, n-arr.get(i), curr,op,i);
                curr.remove(curr.get(curr.size()-1));
            }

        }

    }
}
