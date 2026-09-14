class Solution {
public:
    int fun(vector<int>& coins, int amount, vector<int>& dp)
    {
        if(amount==0) return 0;
        if(amount<0) return 1e7;
        if(dp[amount]!=-1) return dp[amount];
        int ans=1e7;
        for(int i=0;i<coins.size();i++)
        {
            int next=fun(coins,amount-coins[i],dp);
            if(next!=1e7)
            {
                ans=min(ans,1+next);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = fun(coins, amount,dp);
        if(ans == 1e7)
            return -1;
        return ans;
    }
};
