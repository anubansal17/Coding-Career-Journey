void findCombs(int cur, int k, set<vector<int>> &combs, vector <int> &comb, vector<vector<int>> &distList) {
        if(k < 0) {
            return;
        }
        // If k becomes 0, add comb to answer
        if(k == 0) {
            combs.insert(comb);
            return;
        }   
        for (int i = cur; i<distList.size(); i++) {
            int value = distList[i][0];
            int freq = distList[i][1];
            
        if(freq <= 0)
            continue;       
        // If we are choosing present element
        distList[i][1] = freq-1;
        comb.push_back(value);
        findCombs(i, k-value, combs, comb, distList);
        distList[i][1] = freq;
        comb.pop_back();
        }
    }

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        unordered_map <int, int> mp;
        int n = candidates.size();
        for (int i=0; i<n; i++) {
            mp[candidates[i]]++;
        }
        vector <vector<int>> distList(mp.size());
        int i = 0;
        for (auto itr : mp) {
            distList[i].push_back(itr.first);
            distList[i].push_back(itr.second);
            i++;
        }
        set<vector<int>> combSet;
        vector<int> comb;
        int index = 0;
        vector <vector<int>> combs;
        findCombs(index, target, combSet, comb, distList);
        for (auto comb : combSet) {
            combs.push_back(comb);
        }
        return combs;
    }
};
