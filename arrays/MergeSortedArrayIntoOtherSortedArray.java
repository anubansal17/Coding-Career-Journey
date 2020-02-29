public class MergeArrays{
    void moveToEnd(int mPlusn[], int size) {
        int i = size-1;
        for (int j=size-1; j>=0; j--) {
            if(mPlusn[j] != -1) {
                mPlusn[i] = mPlusn[j];
                i--;
            }
        }
    }
    
    void mergeTwoArrays(int N[], int n, int mPlusn[], int m) {
        int i = 0;//current index for N
        int j = n;//current index for already present mPlusn
        int k = 0;//current index for new insertion in mPlusn
        while(k<m+n)
        {
            if(j<m+n && mPlusn[j]<=N[i] || i == n)
            {
                mPlusn[k] = mPlusn[j];
                k++;
                j++;
            }
            else {
                mPlusn[k] = N[i];
                k++;
                i++;
            }
        }
    }
    
    void printSortedArray(int arr[], int n)
    {
        for (int i=0; i<n; i++)
        {
            System.out.print(arr[i] + " ");
        }
    }

     public static void main(String []args){
         MergeArrays mergearray = new MergeArrays(); 
	
		int mPlusN[] = {2, 8, -1, -1, -1, 13, -1, 15, 20}; 
		int N[] = {5, 7, 9, 25}; 
		int n = N.length; 
		int m = mPlusN.length - n; 
		mergearray.moveToEnd(mPlusN, m + n); 
		mergearray.mergeTwoArrays(N, n, mPlusN, m); 
		mergearray.printSortedArray(mPlusN, m + n); 
         
        
     }
}
