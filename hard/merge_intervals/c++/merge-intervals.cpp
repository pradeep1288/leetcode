/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    struct Comp {
        bool operator()(const Interval& l, const Interval& r) {
            return ((l.start<r.start));
        }
    };

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() == 0)  
            return result;
        if (intervals.size() == 1) {
            result.push_back(intervals[0]);
            return result;
        }
        sort(intervals.begin(), intervals.end(), Comp());
        
        Interval tempInterval = intervals[0];
        for (int i = 1; i<intervals.size(); i++) {
            if (intervals[i].start <= tempInterval.end) {
                if (intervals[i].end > tempInterval.end)
                    tempInterval.end = intervals[i].end;
            }
            else {
                result.push_back(tempInterval);
                tempInterval = intervals[i];
            }
        }
        result.push_back(tempInterval);
    
        return result;
    }
    
};
