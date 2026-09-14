class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        int n=inter.size();
        if(n==0) return 0;
        sort(inter.begin(),inter.end());
        vector<int> temp=inter[0];
        int count=0;
        for(int i=1;i<n;i++)
        {
            //overlaping checking
            if(temp[1]>inter[i][0])
            {
                temp[1] = min(temp[1], inter[i][1]);
                count++;
            }
            else{
                temp=inter[i];
            }
        }
        return count;
    }
};
