class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;
        map<int,int> mpp;
        for(int i:hand) mpp[i]++;
        int totalgroup=n/groupSize;
        while(totalgroup>0)
        {
            auto it=mpp.begin();
            int start=it->first;
            for(int i=0;i<groupSize;i++)
            {
                if(mpp.find(start)!=mpp.end())
                {
                    mpp[start]--;
                    if(mpp[start]==0) mpp.erase(start);
                }
                else{
                    return false;
                }
                start=start+1;
            }
            totalgroup--;
        }
        return true;
    }
};
