// Approach 1: Using MinHeaps  - SC: O(maxProfit), TC: O(NLogN) - Better than approach 2 and much cleaner
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

// Approach 2: Using comparator sorting based on profit in desc order
// then traverse through entire Jobs array which is sorted and for each profit traverse through backwards to put it at arr[profit] or arr[profit-1] and soo on..
// Since profit is sorted in decreasing order, we will always have total max profit first by the time all slots are full
#include<bits/stdc++.h>

using namespace std;

// A structure to represent a job 
struct Job {
   // Job Id
   int id; 
   // Deadline of job
   int dead;
   // Profit if job is completed before or on the deadline 
   int profit; 
};

class Solution {
   public:
      // Comparator function to sort jobs in decreasing order of profit
      bool static comparison(Job a, Job b) {
          // Sort by profit in descending order
         return (a.profit > b.profit); 
      }

   // Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {

      // Sort the jobs based on decreasing profit
      sort(arr, arr + n, comparison);

      // Find the maximum deadline among all jobs
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
        // Get the latest deadline
        maxi = max(maxi, arr[i].dead);  
      }

      // Initialize the slot array to track which time slots are taken
      int slot[maxi + 1];
      for (int i = 0; i <= maxi; i++)
        // Mark all slots as unoccupied initially
        slot[i] = -1;  

      int countJobs = 0, jobProfit = 0;

      // Iterate through all jobs to find the best possible schedule
      for (int i = 0; i < n; i++) {
         // Find a slot for the current job (starting from its deadline)
         for (int j = arr[i].dead; j > 0; j--) {
            // If the slot is available
            if (slot[j] == -1) {  
                // Assign the job to the slot
                slot[j] = i;  
                // Increment the number of jobs done
                countJobs++;  
                // Add the profit of the job
                jobProfit += arr[i].profit;  
               break;
            }
         }
      }

      // Return the number of jobs done and the total profit
      return make_pair(countJobs, jobProfit);
   }
};

int main() {
   // Driver code
   int n = 4;
   // Define jobs with id, deadline, and profit
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   // Function call to find the number of jobs done and total profit
   pair < int, int > ans = ob.JobScheduling(arr, n);

   // Output the number of jobs and the total profit
   cout << ans.first << " " << ans.second << endl;

   return 0;
}
