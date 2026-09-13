class Solution {
public:
    int fun(vector<int>& nums,int n,int idx,vector<int>& dp)
    {
        if(idx>=n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int range=min(idx+nums[idx],n-1);
        int ans=INT_MAX;
        for(int i=idx+1;i<=range;i++)
        {
            int next=fun(nums,n,i,dp);
            if(next!=INT_MAX) ans=min(ans,1+next);
        }
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(nums,n,0,dp);
    }
};
