//https://www.interviewbit.com/problems/largest-number/
bool custom_sort(const string &a, const string &b) {
    return a+b > b+a;
}

string Solution::largestNumber(const vector<int> &A) {
    /// 3 30 34 5 9
    /// 9 5 34 3 30
    vector <string> strings{};
    for (auto nums: A) {
        strings.push_back(to_string(nums));
    }
    sort(strings.begin(), strings.end(), custom_sort);
    string ans = "";
    for (auto nums: strings ){
        ans += nums;
    }
    int first_nonzero = 0;
    int n = ans.size();
     for ( ; first_nonzero<n; ++first_nonzero)
     {
         if(ans[first_nonzero] != '0')
         break;
     }
     if(first_nonzero == 0){
         return ans;
     }
     else if(first_nonzero == n){
         return "0";
     }
     else {
         return ans.substr(first_nonzero, n + first_nonzero);
     }
  
}

