class Solution {
public:
    int fun(vector<int>& cost,int idx,int n,vector<int>& dp)
    {
        if(idx==n-1) return cost[n-1];
        if(idx>n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int onestep=fun(cost,idx+1,n,dp);
        int twostep=fun(cost,idx+2,n,dp);
        return dp[idx]=cost[idx]+min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n,-1);
        int ans=min(fun(cost,0,n,dp1),fun(cost,1,n,dp2));
        return ans;
    }
};
