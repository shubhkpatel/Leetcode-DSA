// Given an array of meeting time intervals consisting of start and end times[[s1,e1],[s2,e2],...](si< ei), find the minimum number of conference rooms required.

// Example 1:

// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2
// Example 2:

// Input: [[7,10],[2,4]]

// Output:1

#include <bits/stdc++.h>
using namespace std;

struct Interval{
    int start; int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool static comparator(const Interval &i1, const Interval &i2) {
    if(i1.start != i2.start) return i1.start < i2.start;
    else i1.end < i2.end;
}

int minMeetingRooms(vector<Interval> intervals){
    if(intervals.size() == 0) return 0;
    sort(intervals.begin(), intervals.end(), comparator);
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int rooms = 0;

    min_heap.push(intervals[0].end);
    for(int i=1; i<intervals.size(); i++){
        if(intervals[i].start < min_heap.top()){
            rooms++;
        }else{
            min_heap.pop();
        }
        min_heap.push(intervals[i].end);
    }
    return rooms;
}

int main(){
    //Intervals
    int n;
    cin >> n;

    vector<Interval> intervals(n);

    for(int i=0; i<n; i++){
        int start; int end;
        cin >> start >> end;
        auto interval = Interval(start, end);
        intervals.push_back(interval);
    }

    int ans = minMeetingRooms(intervals);
    cout << ans << endl;
}