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
    int minMeetingRooms(vector<Interval>& inter) {
        map<int,int> mpp;
        int n=inter.size();
        for(int i=0;i<n;i++)
        {
            mpp[inter[i].start]++;
            mpp[inter[i].end]--;
        }

        int overlapcount=0;
        int maxoverlap=0;
        for(auto it:mpp)
        {
            overlapcount+=it.second;
            if(overlapcount>maxoverlap) maxoverlap=overlapcount;
        }
        return maxoverlap;
    }
};
