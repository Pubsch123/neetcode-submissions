/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        map<int,int> mp;
        for(auto i: intervals)
        {
            mp[i.start]++;
            mp[i.end]--;
        }
        int ans = 0, count = 0;
        for(auto i : mp)
        {
            count += i.second;
            ans = max(ans, count);
        }
        return ans;
    }
};
