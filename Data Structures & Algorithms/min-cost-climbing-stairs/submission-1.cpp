class Solution {
   public:
    int table(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        for (int i = 1; i < n; i++) {
            int onestep = dp[i - 1];
            int twostep=0;
            if(i>=2) twostep = dp[i - 2];
            dp[i]=cost[i]+min(onestep,twostep);
        }
        return min(dp[n-2],dp[n-1]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        return table(cost);
    }
};
