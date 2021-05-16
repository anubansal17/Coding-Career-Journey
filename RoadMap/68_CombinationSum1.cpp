// For generating unique combinations, put the generated vectors in a set first
// If not added in set, it will generate duplicate combinations as well
void findCombs(int cur, int k, vector<vector<int>> &combs, vector <int> &comb, vector<int> arr) {
        if(k < 0) {
            return;
        }
        // If k becomes 0, add comb to answer
        if(k == 0) {
            combs.push_back(comb);
            return;
        }   
        for (int i = cur; i<arr.size(); i++) {
            int value = arr[i];     
        // If we are choosing present element
        comb.push_back(value);
        findCombs(i, k-value, combs, comb, arr);
        comb.pop_back();
        }
    }
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> combs;
    vector<int> comb;
    sort(candidates.begin(), candidates.end());
    int index = 0;
    findCombs(index, target, combs, comb, candidates);
    return combs;
    }
};
