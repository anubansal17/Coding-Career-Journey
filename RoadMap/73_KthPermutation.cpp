// Approach 1- While generating permutations, only add permuattions whose length is n
// Also, while adding these permutations keep a check on number of such permuations, if we reached the desired number
// - permutation, print it
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
    for(int i=1; i<=n; i++)
    {
        nums.push_back(i);
    }
    for(int i=1; i<k; i++)
    {
        next_permutation(nums.begin(), nums.begin() + n);
    }
        string s = "";
        for(int i=0; i<n; i++)
        {
            s = s + to_string(nums[i]);
        }
        return s;
    }
};
