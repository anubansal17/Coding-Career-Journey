// Approach 1: Space Complexity: O(2n), TC: O(nlogn)
// 1. Create Pairs of arrival and departure
// 2. Sort acc to arrivals
// 3. maintain a min que for earliest departure time of already arrived trains
// 4. if there's overlap pop and push this new departure time
// 5. ELse push into queue a new item
// 6. return size of queue at the end
//Approach 2: Most Optimized one Approach 2: Two pointers TC: O(nlogn), SC: O(1)

//Approach 1 Implementation:
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        vector<pair<int, int>> trainPairs;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            trainPairs.push_back({arr[i], dep[i]});
        }
        sort(trainPairs.begin(), trainPairs.end());
        priority_queue<int, vector<int>, greater<int>> standingTrains;
        standingTrains.push(trainPairs[0].second);
        int lastDepart = trainPairs[0].second;
        for(int i=1; i<n; i++) {
            lastDepart = standingTrains.top();
            //cout<<lastDepart<<" "<<trainPairs[i].first<<endl;
            if(lastDepart < trainPairs[i].first) {
                //cout<<(lastDepart > trainPairs[i].first);
                standingTrains.pop();
                standingTrains.push(trainPairs[i].second);
            } else{
                standingTrains.push(trainPairs[i].second);
            }
        }
        return standingTrains.size();
    }
};

// Approach 2 Implementation
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i = 0, j = 0;
        int platforms = 0;
        int maxPlatforms = 0;
        while(i<n ) {
            if(arr[i]<=dep[j]) {
                platforms++;
                i++;
            }else{
                platforms--;
                j++;
            }
            maxPlatforms = max(maxPlatforms, platforms);
        }
        return maxPlatforms;
    }
};
