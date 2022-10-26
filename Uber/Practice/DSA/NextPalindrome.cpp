class Solution {
public:
    string nextPalindrome(string num) {
        int n = num.size();
        int n1 = n/2;
        string s = num.substr(0, n1);
        cout<<s<<endl;
        nextPermutation(s);
        cout<<s<<endl;
        string output = s;
        if(output == "")
            return output;
        if(n%2) {
            output += num[n/2];
        }
        for(int i=n1-1; i>=0; i--) {
            output += s[i];
        }
        return output;
    }
    void nextPermutation(string &s) {
        int n = s.size();
        vector<int> nums;
        for(int i=0; i<n; i++) {
            nums.push_back(s[i]-'0');
        }
        int index = -1;
        for(int i=n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                index = i;
                break;
            }
        }
        if(index == -1) {
             s = "";
            return;
        }
        int index1 = -1;
        for(int i=n-1; i>index; i--) {
            if(nums[i] > nums[index]) {
                index1 = i;
                break;
            }
        }
        swap(nums[index], nums[index1]);
        reverse(nums.begin()+index+1, nums.end());
        for(int i=0; i<n; i++) {
            s[i] = nums[i]+'0';
        }
    }
};


// 123241
//     123421
