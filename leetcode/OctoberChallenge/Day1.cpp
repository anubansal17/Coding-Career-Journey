class RecentCounter {
    queue<int> que;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        que.push(t);
        int start=t-3000;
        int end=t;
        while(que.front()<start){
            que.pop();
        }
        return que.size(); 
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
