//https://www.interviewbit.com/problems/count-element-occurence/
//Method 1: Using Maps - Time Complexity: O(logn), Space Complexity: O(n)
/*
int Solution::findCount(const vector<int> &A, int B) {
    map <int, int> mp;
    map <int, int> :: iterator it;
    int n = A.size();
    for(int i=0; i<n; i++){
        if(mp.find(A[i]) == mp.end()){
             mp.insert({A[i],1});
        }else{
           it = mp.find(A[i]);
           it->second++;
        }
       
    }
    it = mp.find(B);
    if(it != mp.end()){
        return it->second;
    }
    return 0;
}
*/
//Method 2: Using binary search - Time complexity: O(logn), Space Complexity: O(1)
int binary_search(vector <int> A, int B, bool first_occurence){
    int n = A.size();
    int ans = -1;
    int l = 0;
    int r = n-1;
    
    while(l<=r){
        int mid = l + (r-l)/2;
        if(A[mid] == B){
            ans = mid;
          
            if(first_occurence){
                r = mid - 1;
        
            }else{
                l = mid + 1;
            }
        }
        else if(A[mid]<B){
            l = mid + 1;
        } else{
            r = mid - 1;
        }
    }
    
    return ans;
}
int Solution::findCount(const vector<int> &A, int B) {
 int ans = 0;
 int first_index = -1;
 int last_index = -1;
 first_index = binary_search(A, B, true);
 last_index = binary_search(A, B, false);
 
 if(first_index != -1){
  ans = last_index - first_index + 1;  
 }
 
 return ans;
}
