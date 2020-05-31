// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3345/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // We have used multimaps as multiple points can have same distance from origin
        multimap <int, int> dist;
        vector <vector<int>> ans;
        int n = points.size();
        for (int i=0; i<n; i++) {
            dist.insert({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
        }
        map <int, int> :: iterator it;
        it = dist.begin();
        for (int i=0; i<K; i++) {
            ans.push_back(points[it->second]);
            it ++;
        }
        return ans;
    }
};
