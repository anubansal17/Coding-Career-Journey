class MovingAverage {
public:
    queue <int> que;
    int n;
    int sum = 0;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        n = size;
    }
    
    double next(int val) {
       que.push(val);
        sum += val;
        if(que.size() < n)
            return sum*1.0/que.size();
        if(que.size() > n)
        {
            sum -= que.front();
            que.pop();
        }
        return sum*1.0/n;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
