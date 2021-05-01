class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int pos = arr1.size() - 1;
        int j = n - 1;
        int i = m - 1;
        while(i >= 0 && j >= 0) {
            if(arr1[i] >= arr2[j]) {
                arr1[pos] = arr1[i];
                pos --;
                i --;
            }else {
                arr1[pos] = arr2[j];
                pos --;
                j --;
            }
        }
        while(i >= 0) {
            arr1[pos] = arr1[i];
            pos --;
            i --;
        }
        while(j >= 0) {
            arr1[pos] = arr2[j];
            pos --;
            j --;
        }
    }
};
