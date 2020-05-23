//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3337/

bool cmp(pair<char, int> p, pair<char, int> q){
        return p.second>q.second;
    }
class Solution {
public:
    string frequencySort(string s) {
        map <char, int> mp;
        int n = s.length();
        for (int i=0; i<n; i++){
            mp[s[i]]++;
        }
   vector <pair<char, int> > v;
        map <char, int> :: iterator it;
    for (it = mp.begin(); it != mp.end(); it++){
        v.push_back(make_pair(it->first, it->second));
    }
    sort(v.begin(), v.end(), cmp);
        s = "";
        for (int i=0; i<v.size(); i++){
            for (int j=0; j<v[i].second; j++){
                s += v[i].first;
            }
        }
        return s;
    }
 
};
