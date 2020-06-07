// https://leetcode.com/explore/featured/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3352/
bool  customSort(vector <int> x, vector <int> y) {
    if(x[0] != y[0]) {
        return x[0] > y[0];
    }
    else {
        return x[1] < y[1];
    }
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>>result;
        sort(people.begin(), people.end(), customSort);
        int n = people.size();
        for (int i=0; i<n; i++) {
            result.insert(result.begin()+people[i][1], people[i]);
        }
        return result;
    }
};
