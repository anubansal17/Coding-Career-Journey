//https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/
class Solution {
public:
    //if(y2-y1)/(x2-x1) = m
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if((coordinates[1][0] - coordinates[0][0]) == 0){
            return false;
        }
        float slope = (coordinates[1][1] - coordinates[0][1])/(coordinates[1][0] - coordinates[0][0]);
        for(int i=2; i<n; i++){
            if((coordinates[i][0] - coordinates[0][0]) == 0){
                return false;
            }
          if(((float)(coordinates[i][1] - coordinates[0][1])/(coordinates[i][0] - coordinates[0][0])) != slope){
              
              return false;
          }  
        }
        return true;
    }
};
