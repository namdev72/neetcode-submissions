class Solution {
public:
    int time(vector<int>& piles,int t)
    {
        int sum=0;
        for(auto it:piles)
        {
            sum+=ceil(double(it)/t);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi=*max_element(piles.begin(),piles.end());
        int l=1;
        int ans=h;
        int m;
        while(l<=hi)
        {
            m=l+(hi-l)/2;
            if(time(piles,m)<=h)
            {
                ans=m;
                hi=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};
