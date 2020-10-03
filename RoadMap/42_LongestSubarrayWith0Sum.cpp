/*
Approach1 : Brute force, T.C- O(n^2), S.C- O(1)
Approach2 : Using hashing, T.C- O(n), S.C- O(n)
- Put in sum till current element and its index in hash map, if it doesn't exist already
- Idea is if sum of first i elements is x and sum of first j is also x where j>i
- It means sum of elements between index i+1 and j is 0, we will calculate its length
- and check if it is the maximum length or not
*/
/*You are required to complete this function*/

int maxLen(int A[], int n)
{
    unordered_map <int, int> mp;
    int maxLength = 0;
    int sum = 0;
    int i = 0;
    for(int i=0; i<n; i++) {
        sum += A[i];
        if(sum == 0) {
            maxLength = i+1;
        }
        else {
         // If sum doesn't exist in the map
        if(mp.find(sum) == mp.end()){
            mp[sum] =  i;
        } else {
            int curLength = i - mp[sum];
            maxLength = max(curLength, maxLength);
            }   
        }
    }
    return maxLength;
}
