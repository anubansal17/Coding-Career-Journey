/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
      vector<int> dimensions = binaryMatrix.dimensions();
        int rows = dimensions[0];
        int cols = dimensions[1];
        int minIndex = 100;
        for(int i=0; i<rows; i++) {
          int index = search(i, binaryMatrix, cols);
            if(index != -1)
                minIndex = min(minIndex, index);
        }
        return minIndex != 100 ? minIndex : -1;
    }
    int search(int row, BinaryMatrix &binaryMatrix, int col) {
        int start = 0;
        int end = col;
        int mid = start + (end - start)/2;
        bool flag = 0;
        while(start < end) {
            mid = start + (end - start)/2;
            if(binaryMatrix.get(row, mid) == 1) {
                end = mid;
                flag = 1;
            } else
                start = mid+1;
        }
        return flag ? end : -1;
    }
};
