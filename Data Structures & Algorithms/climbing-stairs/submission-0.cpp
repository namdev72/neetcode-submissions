class Solution {
   public:
    int fun(int i, int n,vector<int>& dp) {
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        if (i==n) return 1;
         
         int first=fun(i+1,n,dp);
         int second=fun(i+2,n,dp);
         return dp[i]=first+second; 
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return fun(0,n,dp);
    }
};
