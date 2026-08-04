class Solution {
public:
    int fun(int idx,vector<int>& nums,vector<int>& dp)
    {
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        //take
        int take=nums[idx]+fun(idx+2,nums,dp);
        int nottake=0+fun(idx+1,nums,dp);
        return dp[idx]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(0,nums,dp);
    }
};
