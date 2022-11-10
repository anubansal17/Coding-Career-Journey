#include <iostream>
#include <bits/stdc++.h>
using namespace std;
///mp[0] =  {"req1"};
// mp[1] = {"req2"}
map<int, queue<string>> queMap;
bool addRequest(int t, string req) {
    if(queMap[t].size() >= 1000)
            return false;
    queMap[t].push(req);
    return true;
}
void processRequest() {
    auto itr = queMap.begin();
    queue<string> que = itr->second;
    string request = que.front();
    que.pop();
    int t = itr->first;
    if(queMap[t].size() == 0) {
        queMap.erase(t);
    }
}
//t = 3
// t = 1
void dropRequests(int t) {
    for(auto cur : queMap) {
        if(cur.first < t-2) {
            queMap.erase(cur.first);
        }
        break;
    }
}
int main() {
    // you can write to stdout for debugging purposes, e.g.
    std::cout << "This is a debug message" << std::endl;
    bool response = addRequest(0, "req1");
    addRequest(1, "req2");    
    processRequest();

    cout<<response;
    if(response) {
        processRequest();
    }
    return 0;
} 
