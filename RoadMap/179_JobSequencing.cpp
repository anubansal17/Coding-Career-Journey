class Solution 
{
    public:
    bool static comparison(Job a, Job b)
    {
        return (a.dead < b.dead);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       sort(arr, arr+n, comparison);
       priority_queue<int, vector< int>, greater< int>> minHeap;
       minHeap.push(arr[0].profit);
       for(int i=1; i<n; i++) {
            // int cur = minHeap.top();
            minHeap.push(arr[i].profit);
            if (minHeap.size() > arr[i].dead) {
                //minHeap.push(jobs[i][1]);
                minHeap.pop();
            }
            // else if (no < jobs[i][0])
            //     minHeap.push(jobs[i][1]);
        }
       vector<int> ans;
       int size = minHeap.size();
       ans.push_back(size);
       int profit = 0;
       while(!minHeap.empty()) {
           profit += minHeap.top();
           minHeap.pop();
       }
       ans.push_back(profit);
       return ans;
    } 
};
