#include <bits/stdc++.h>
using namespace std;
enum Day{
    Mon=1, Tue=2, Wed=3, Thur=4, Fri=5, Sat=6, Sun=7
};
unordered_map<string, int> dayMap;
class Time {
    public:
    string day;
    int hours;
    int mins;
    
    Time() {
        
    }
    Time(string s) {
        int index = s.find(' ');
        int index1 = s.find(':');
        day = s.substr(0, index);
        hours = stoi(s.substr(index+1, index1));
        mins = stoi(s.substr(index1+1));
        
    }
};

class Interval {
    public:
    Time startTime;
    Time endTime;
    
     Interval(string s) {
        startTime = Time(s.substr(0, s.find("->")));
        endTime = Time(s.substr(s.find("->")+3));
     }
};

class MergeIntervals{
    public:
    static bool cmp(Interval &interval1, Interval &interval2) {
        if(interval1.startTime.day == interval2.startTime.day) {
            return interval1.startTime.hours == interval2.startTime.hours ? 
                    interval1.startTime.mins < interval2.startTime.mins :
                    interval1.startTime.hours < interval2.startTime.hours;
        }
        return dayMap[interval1.startTime.day] < dayMap[interval2.startTime.day];
    }
    vector<Interval> mergeIntervals(vector<Interval> &intervals) {
        int n = intervals.size();
        dayMap["Mon"] = 1;
        dayMap["Tue"] = 2;
        dayMap["Wed"] = 3;
        dayMap["Thur"] = 4;
        dayMap["Fri"] = 5;
        dayMap["Sat"] = 6;
        dayMap["Sun"] = 7;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        Interval cur = intervals[0];
        for(int i=1; i<n; i++) {
            bool merge = false;
            if(dayMap[intervals[i].startTime.day] < dayMap[cur.endTime.day]) 
                merge = true;
            else if(dayMap[intervals[i].startTime.day] == dayMap[cur.endTime.day]) {
                if(intervals[i].startTime.hours < cur.endTime.hours) {
                    merge = true;
                } else if(intervals[i].startTime.hours == cur.endTime.hours) {
                    merge = intervals[i].startTime.mins <= cur.endTime.mins;
                }
            }
            
            if(!merge) {
                //cout<<"yf"<<endl;
                ans.push_back(cur);
                cur = intervals[i];
            } else {
                //cout<<"f";
                if(dayMap[intervals[i].endTime.day] > dayMap[cur.endTime.day])
                    cur.endTime = intervals[i].endTime;
                else if((dayMap[intervals[i].endTime.day] == dayMap[cur.endTime.day]) and cur.endTime.hours*60+cur.endTime.mins < intervals[i].endTime.hours*60+intervals[i].endTime.mins)
                    cur.endTime = intervals[i].endTime;
            }
        }
        ans.push_back(cur);
        // Interval i = cur;
        // cout<<i.startTime.day<<" "<<i.startTime.hours<<":"<<i.startTime.mins<<" -> ";
        // cout<<i.endTime.day<<" "<<i.endTime.hours<<":"<<i.endTime.mins<<endl;
        return ans;
    }
    
    Interval convertToIntervals(string intervalString) {
        Interval interval(intervalString);
        return interval;
    }
};

class Schedule{
    vector<Interval> intervalSet;
};
int main()
{
    
    string s1 = "Mon 9:00 -> Mon 17:00";
    string s2 = "Tue 9:00 -> Tue 17:00";
    
    Interval i1(s1);
    Interval i2(s2);
    
    vector<Interval> intervals;
    intervals.push_back(i1);
    intervals.push_back(i2);
    
    MergeIntervals main;
    vector<Interval> ansVector = main.mergeIntervals(intervals);
    
    for(auto i: ansVector) {
        cout<<i.startTime.day<<" "<<i.startTime.hours<<":"<<i.startTime.mins<<" -> ";
        cout<<i.endTime.day<<" "<<i.endTime.hours<<":"<<i.endTime.mins<<endl;
    }
    return 0;
}
