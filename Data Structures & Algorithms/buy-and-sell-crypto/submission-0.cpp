class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> pre(n,-1);
        int l=prices[n-1];
        pre[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(prices[i]<l)
            {
                pre[i]=l;
            }else{
                l=prices[i];
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(pre[i]-prices[i]>0)
            {
                ans=max(ans,pre[i]-prices[i]);
            }
        }
        return ans;
        
    }
};
