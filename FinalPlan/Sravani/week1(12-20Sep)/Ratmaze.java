public class RatInMaze {
    public static void main(String[] args) {
        int[][] arr = new int[][]{
                {1,0,0,1},
                {3,0,0,1},
                {0,0,0,1},
                {0,0,0,1}
        };
        solve(4,arr);
    }

    static void solve(int n, int[][] arr){
        int[][] op = new int[][]{
                {0,0,0,0},
                {0,0,0,0},
                {0,0,0,0},
                {0,0,0,0}
        };
        if(ratUtil(0,0,n,arr,op)){
            printSolution(op);
        }
        else System.out.println("no path ");
    }

    static void printSolution(int[][] op){
        for(int i = 0 ; i < op.length ; i++){
            for(int j = 0 ; j< op[0].length ; j++){
                System.out.print(op[i][j]+" ");
            }
            System.out.println();
        }
    }

    static boolean ratUtil(int i , int j, int n, int[][] arr, int[][] op){
        System.out.println(i+ " " + j);
        if(i == n-1 && j == n-1)
            return true;

        if(isSafe(i,j,arr)){
            op[i][j] =1;
            for(int x = 1 ; x <= arr[i][j]&& x<n ; x++){
                if(ratUtil(i+x, j, n , arr, op))
                    return true;
                else if (ratUtil(i, j+x, n , arr, op))
                    return true;

            }
            op[i][j] = 0;
            return false;
        }
        return false;
    }

    static boolean isSafe(int i,int j, int[][] arr){
        if(i>= arr.length || j >= arr[0].length) return false;
        if(arr[i][j] == 0) return false;
        return true;
    }
}
