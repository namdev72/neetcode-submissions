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
    bool canAttendMeetings(vector<Interval>& inter) {
        int n=inter.size();
        if(n<=1) return true;
        sort(inter.begin(),inter.end(),
        [](const Interval& a,const Interval& b)
        {
            return a.start<b.start;
        }
        );
        Interval temp=inter[0];
        for(int i=1;i<n;i++)
        {
            //overlaping case
            if(temp.end>inter[i].start) return false;
            else temp=inter[i];
        }
        return true;

    }
};
