// Problem: 
// Ans will be the number which is present in second position in all subsets corrseponding to unique elements at first position but not present in any of the subsets at first position and whose occurences is eqaul to N-1
// Time Complexity - O(nlogn)
// Space Complexity - O(n)
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int n = trust.size();
        if(N == 1 and n == 0){
            return 1;
        }
        set <int> uniqueFirstElem;
        map <int, int> possibleAns;
        map <int, int> :: iterator it;
        for (int i=0; i<n; i++){
            it = possibleAns.find(trust[i][1]);
            uniqueFirstElem.insert(trust[i][0]);
            if(it == possibleAns.end()){
                possibleAns.insert({trust[i][1], 1});
            }else{
                it->second ++;
            }
        }
        for (auto it = possibleAns.begin(); it != possibleAns.end(); it++){
            if(it->second == N-1 and uniqueFirstElem.find(it->first) == uniqueFirstElem.end()){
                return it->first;
            }
        }
        return -1;
    }
};
