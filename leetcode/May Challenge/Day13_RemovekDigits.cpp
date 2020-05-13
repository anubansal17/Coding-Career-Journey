//https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/
class Solution {
    //Approach:
    //-Start from left
    //-keep track of k number of largest digits till current element
    //-If a digit happens to be zero then delete the largest digit before it 
    string reduceString(string str, int k, string ans){
        int len = str.length();
        if(k == 0){
            ans += str;
            return ans;
        }else if(len <= k){
            return ans;
        }else{
           int min = 0;
            for(int i=1; i<=k; i++){
                if((str[i]-'0') < (str[min] - '0')){
                    min = i;
                }
            }
            ans += str[min];
            k = k-min;
            ans = reduceString(str.substr(min+1, len), k, ans);
        }
        return ans;
    }
    
    
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int n = num.length();
        ans = reduceString(num, k, ans);
        int i = 0;
        while(ans[i] == '0'){
           i++;
        }
        ans = ans.substr(i, ans.length());
        if(ans == ""){
            ans = '0';
        }
        return ans;
        
    }
};
