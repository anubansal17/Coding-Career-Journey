class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> remCost;
        for(int i=0; i<n; i++) {
            remCost.push_back(gas[i]-cost[i]);
        }
        for(int i=1; i<n; i++) {
            remCost[i] += remCost[i-1];
        }
        if(remCost[n-1] < 0)
            return -1;
        int minm = remCost[0];
        int index = 0;
        for(int i=1; i<n; i++) {
            if(remCost[i] < minm) {
                minm = remCost[i];
                index = i;
            }
        }
        return (index+1)%n;
    }
};
