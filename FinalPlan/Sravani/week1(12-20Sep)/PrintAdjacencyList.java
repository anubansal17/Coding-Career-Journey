package com.geeksforgeeks.graphs;
import java.util.Scanner;

public class PrintAdjacencyList {

    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            int v = sc.nextInt();
            int e = sc.nextInt();
            int a[][] = new int[e][2];
            for(int i=0;i<e;i++)
            {
                a[i][0] = sc.nextInt();
                a[i][1] = sc.nextInt();
            }
            for(int i=0;i<v;i++)
            {
                System.out.print(i);
                for(int j=0;j<e;j++)
                {
                    if(a[j][0]==i)
                        System.out.print("-> " + a[j][1]);
                    if(a[j][1]==i)
                        System.out.print("-> " + a[j][0]);
                }
                System.out.println();
            }
        }
    }
}

