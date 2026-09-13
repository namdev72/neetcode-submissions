class Solution {
public:
    bool fun(vector<int>& nums,int idx,int n,vector<int>& dp)
    {
        if(idx>=n-1) return true;
        if(nums[idx]==0) return false;
        if(dp[idx]!=-1) return dp[idx];
        int range=min(nums[idx]+idx,n-1);
        for(int i=idx+1;i<=range;i++)
        {
            if(fun(nums,i,n,dp)) return dp[idx]=1;
        }
        return dp[idx]=0;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(nums,0,n,dp);
    }
};
