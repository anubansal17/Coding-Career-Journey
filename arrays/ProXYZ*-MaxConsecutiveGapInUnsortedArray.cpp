int Solution::maximumGap(const vector<int> &A) {
   /* O(nlogn)
    vector <int> B;
    B  = A;
    int max = INT_MIN;
    sort(B.begin(), B.end());
    for (int i=0; i<B.size()-1; i++) {
        if(abs(B[i]-B[i+1])>max)
        {
            max = abs(B[i]-B[i+1]);
        }
    }
    if(B.size()<2)
    {
        return 0;
    }
    return max;
    */
  
  // Method 2: Much Efficient
  // finding max and min of the array
  // MaxGap would be max if all the numbers are max or min, making maximum maxGap = max-min
  // MaxGap would be minimum if the all the numbers are equally spaced, minimum maxGap = (max-min)/(N-1)
  // As gap would be an integer always, so we added 1 to consider always the ceiling
  // Now, we know value of maxGap would lie between minimum maxGap and maximum maxGap
  // We need to make buckets now of size minimum maxGap, as we want maximum value of maxGap that would never be between elements in same bucket
  // All we need to have is maximum element from previous bucket and minimum element from current bucket and tke difference of both
  // We will put the elements in these buckets according to their values and keep a track of minimum and maximum of these buckets
  
  int maxm = *max_element(A.begin(), A.end());
  int minm = *min_element(A.begin(), A.end());
  int n = A.size();
  int gap = ((maxm-minm)/n-1);
  // minimum value of maxGap will be gap
  // example: 5 1 10
  // value[index] = min + gap*index
  vector<pair<int, int>> buckets(A.size(), make_pair(INT_MAX, INT_MIN));
    for(int i=0; i<A.size(); i++)
    {
        int index = gap? (A[i] - minm)/gap :(A[i] - minm);
        buckets[index].first = min(buckets[index].first, A[i]);
        buckets[index].second = max(buckets[index].second, A[i]);
    }
    int i=0;
    int j = 1;
    int maxGap = 0;
    while(buckets[i].first == INT_MAX)
        i++;
    j = i+1;
    while(j<A.size())
    {
        if(buckets[j].first == INT_MAX)
        {
            j++;
            continue;
        }
        maxGap = max(maxGap, buckets[j].first-buckets[i].second);
        i = j;
        j++;
        
    }
    return maxGap;
  
}
