// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3461/
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        while(s[0] == ' '){
                s = s.substr(1);
            }
            if(s[0] == ' '){
                return 0;
            } else {
                return s.substr(0, s.find(' ')).length();
            }
        return 0;
    }
};

// Using sstream

int lengthOfLastWord(string s) {
	istringstream ss(s);
	while(ss >> s);
	return s[0] == ' ' ? 0 : s.length();
}
