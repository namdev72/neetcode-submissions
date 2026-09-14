class Solution {
public:
    int table(int n)
    {
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            int onestep=dp[i-1];
            int secondstep=0;
            if(i>=2) secondstep=dp[i-2];
            dp[i]=onestep+secondstep;
        }
        return dp[n];
    }
    int climbStairs(int n) {
        return table(n);
    }
};
