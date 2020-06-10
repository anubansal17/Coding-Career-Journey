// https://leetcode.com/explore/featured/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3351/
class Solution {
    // Approach:
    // Run through the given vector and keep suming the elements in each position
    // Keep the sum at every element in other vector so that we can keep track of the range of numbers     // any index can have
    // As weight can never be zero so we don't have to consider that case
    // In pickIndex function, we need to use  random function to generate random number bertween 1 to       // max sum
    // As our resulting array is containing cummulative weights, so it would be already in increasing       // order
    // As it is already in sorted order, we can use binary_search for searching the index for random       // weight
    // Probability of getting any element is weight at any index/ sum of all weights
    // cumArray = [1, 4], ele = 2
    public:
    vector <int> cumWeight;
    int sum;
    Solution(vector<int>& w) {
        int n = w.size();
        sum = 0;
        for (int i=0; i<n; i++) {
            sum += w[i];
            cumWeight.push_back(sum);
        }
    }
    
    int pickIndex() {
        // random value picked should be less than maxSum
       int ele = rand() % sum; 
        return binary_search(ele + 1);
    }
    int binary_search(int ele) {
        int left = 0;
        int ans = 0;
        int right = cumWeight.size() - 1;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(cumWeight[mid] == ele) {
                return mid;
            }
            else if(cumWeight[mid] < ele) {
                left = mid + 1;
                ans = left;
            } else {
                
                right = mid - 1;
            }
        }
         return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
