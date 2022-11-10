/*
Suppose we have an unsorted log file of accesses to web resources. Each log entry consists of an access time, the ID of the user making the access, and the resource ID. 

The access time is represented as seconds since 00:00:00, and all times are assumed to be in the same day.

Examples:
logs1 = [
    ["200", "user_1", "resource_5"],
    ["3", "user_1", "resource_1"],
    ["620", "user_1", "resource_1"],
    ["620", "user_3", "resource_1"],
    ["34", "user_6", "resource_2"],
    ["95", "user_9", "resource_1"],
    ["416", "user_6", "resource_1"],
    ["58523", "user_3", "resource_1"],
    ["53760", "user_3", "resource_3"],
    ["58522", "user_22", "resource_1"],
    ["100", "user_3", "resource_6"],
    ["400", "user_6", "resource_2"],
]

logs2 = [
    ["357", "user", "resource_2"],
    ["1262", "user", "resource_1"],
    ["1462", "user", "resource_2"],
    ["1060", "user", "resource_1"],
    ["756", "user", "resource_3"],
    ["1090", "user", "resource_3"],
]

logs3 = [
    ["300", "user_10", "resource_5"],
]

logs4 = [
    ["1", "user_96", "resource_5"],
    ["1", "user_10", "resource_5"],
    ["301", "user_11", "resource_5"],
    ["301", "user_12", "resource_5"],
    ["603", "user_12", "resource_5"],
    ["1603", "user_12", "resource_7"],
]

Write a function that takes the logs and returns the resource with the highest number of accesses in any 5 minute window, together with how many accesses it saw.

Expected Output:
most_requested_resource(logs1) # => ('resource_1', 3) [resource_1 is accessed at 416, 620, 620]
most_requested_resource(logs2) # => ('resource_1', 2) [resource_1 is accessed at 1060, 1262]
most_requested_resource(logs3) # => ('resource_5', 1) [resource_5 is accessed at 300]
most_requested_resource(logs4) # => ('resource_5', 4) [resource_5 is accessed at 1, 1, 301, 301]

Complexity analysis variables:

n: number of logs in the input
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
unordered_map<string, vector<int>> findLogs(vector<vector<string>> logs) {
  int n = logs.size();
  unordered_map<string, vector<int>> timeMap;
  for(int i=0; i<n; i++ ){ 
    if(timeMap.find(logs[i][1]) == timeMap.end()) {
      timeMap[logs[i][1]].push_back(stoi(logs[i][0]));
    } else {
      if(timeMap[logs[i][1]].size() == 1) {
        int minm = min(timeMap[logs[i][1]][0], stoi(logs[i][0]));
        int maxm = max(timeMap[logs[i][1]][0], stoi(logs[i][0]));
        timeMap[logs[i][1]].pop_back();
        timeMap[logs[i][1]].push_back(minm);
        timeMap[logs[i][1]].push_back(maxm);
      } else {
        int first = timeMap[logs[i][1]][0];
        int second = timeMap[logs[i][1]][1];
        if(stoi(logs[i][0]) > second) {
          timeMap[logs[i][1]][1] = stoi(logs[i][0]);
        } else if(stoi(logs[i][0]) < first) {
          timeMap[logs[i][1]][0] = stoi(logs[i][0]);
        }
      }
    }
  }
  for(auto itr : timeMap) {
    if(itr.second.size() == 1) {
      string key = itr.first;
      timeMap[key].push_back(itr.second[0]);
    }
  }
  return timeMap;
}
//distinct: O(m) - m distinct users
int main() {
  vector<vector<string>> logs1 = {
    {"200", "user_1", "resource_5"},
    {"3", "user_1", "resource_1"},
    {"620", "user_1", "resource_1"},
    {"620", "user_3", "resource_1"},
    {"34", "user_6", "resource_2"},
    {"95", "user_9", "resource_1"},
    {"416", "user_6", "resource_1"},
    {"58523", "user_3", "resource_1"},
    {"53760", "user_3", "resource_3"},
    {"58522", "user_22", "resource_1"},
    {"100", "user_3", "resource_6"},
    {"400", "user_6", "resource_2"},
  };

  vector<vector<string>> logs2 = {
    {"357", "user", "resource_2"},
    {"1262", "user", "resource_1"},
    {"1462", "user", "resource_2"},
    {"1060", "user", "resource_1"},
    {"756", "user", "resource_3"},
    {"1090", "user", "resource_3"},
  };

  vector<vector<string>> logs3 = {
    {"300", "user_10", "resource_5"},
  };

  vector<vector<string>> logs4 = {
    {"1", "user_96", "resource_5"},
    {"1", "user_10", "resource_5"},
    {"301", "user_11", "resource_5"},
    {"301", "user_12", "resource_5"},
    {"603", "user_12", "resource_5"},
    {"1603", "user_12", "resource_7"},
  };
 
/*unordered_map<string, vector<int>> timeMap = findLogs(logs1);
for(auto itr: timeMap) {
  cout<<itr.first<<" "<<itr.second[0]<<" "<<itr.second[1]<<endl;
}
unordered_map<string, vector<int>> timeMap1 = findLogs(logs2);
for(auto itr: timeMap1) {
  cout<<itr.first<<" "<<itr.second[0]<<" "<<itr.second[1]<<endl;
}
unordered_map<string, vector<int>> timeMap2 = findLogs(logs3);
for(auto itr: timeMap2) {
  cout<<itr.first<<" "<<itr.second[0]<<" "<<itr.second[1]<<endl;
}
unordered_map<string, vector<int>> timeMap3 = findLogs(logs4);
for(auto itr: timeMap3) {
  cout<<itr.first<<" "<<itr.second[0]<<" "<<itr.second[1]<<endl;
}*/
  return 0;
}
