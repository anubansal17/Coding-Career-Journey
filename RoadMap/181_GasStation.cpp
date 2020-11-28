int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int total = 0, tank = 0, index = 0;
        for (int i = 0; i < cost.size(); i++) {
            int consume = gas[i] - cost[i];			
            tank += consume;
            if (tank < 0) {
                index = i + 1;
                tank = 0;
            }
            total += consume;			
        }		
        return total < 0 ? -1 : index; // check if total -ve which means we can't complete the trip.
    }
