//https://www.interviewbit.com/problems/excel-column-title/
string Solution::convertToTitle(int A) {
    string ans = "";
    while(A>0){
        int rem = A%26;
        if(rem == 0){
            rem = 26;
        }
        ans += char (rem + 64);
        if(rem == 26){
            //-1 is to subtract 26 from the number
            A = (A/26)-1;
        }
        else{
           A = A/26;  
        }
       
    }
    int n = ans.length();
        for (int i = 0; i < n / 2; i++) 
        swap(ans[i], ans[n - i - 1]);
    return ans;
}
