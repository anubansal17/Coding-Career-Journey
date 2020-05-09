// Problem: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/674/
class Solution {
    bool search(int num, vector<int>& arr){
        int l = 0;
        int r = arr.size()-1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid] == num){
                arr.erase(arr.begin()+mid);
                return true;
            }else if(num > arr[mid]){
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        return false;
    }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        //To check if the array is already sorted, run a loop to check that before sorting to minimize the complexity
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector <int> ans;
        if(n1<n2){
           for(int i=0; i<n1; i++){
               if(search(nums1[i], nums2)){
                   ans.push_back(nums1[i]);
               }
           } 
        }else{
            for (int i=0; i<n2; i++){
                if(search(nums2[i], nums1)){
                    ans.push_back(nums2[i]);
                }
            }
        }
        return ans;
    }
};
