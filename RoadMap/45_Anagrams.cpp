class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector <string>> strMap;
        for (string str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            strMap[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = strMap.begin(); it != strMap.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
