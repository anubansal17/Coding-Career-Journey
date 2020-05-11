//https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/
class Solution {
    vector<vector<int>> colorPixel(vector<vector<int>> image, int i, int j, int oldColor, int newColor){        
        int n = image.size();
        int m = image[0].size();//no. of columns
        if(image[i][j] == newColor){
            return image;
        }
        image[i][j] = newColor;
        if((i>0) and (image[i-1][j] == oldColor)){
            image = colorPixel(image, i-1, j, oldColor, newColor);
        }if((j > 0) and (image[i][j-1] == oldColor)){
            image = colorPixel(image, i, j-1, oldColor, newColor);
        } if((i+1<n) and (image[i+1][j] == oldColor)){
            image = colorPixel(image, i+1, j, oldColor, newColor);
        } if((j+1<m )and (image[i][j+1] == oldColor)){
            image = colorPixel(image, i, j+1, oldColor, newColor);
        }
                                                                                                            return image;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      vector <vector <int>> ans;
      ans = colorPixel(image, sr, sc, image[sr][sc], newColor);
        return ans;
    }
};
