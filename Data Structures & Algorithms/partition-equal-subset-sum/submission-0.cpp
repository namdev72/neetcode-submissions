class Solution {
public:
    bool fun(vector<int>& nums,int sum,int idx,vector<vector<int>>& dp)
    {
        int n=nums.size();
        if(idx==n-1)
        {
            return sum==nums[n-1];
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool take=0;
        if(nums[idx]<=sum)
        {
            take=fun(nums,sum-nums[idx],idx+1,dp);
        }
        bool notake=fun(nums,sum,idx+1,dp);
        return dp[idx][sum]=take || notake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i:nums)
        {
            sum+=i;
        }
        if(sum%2!=0) return false;
        sum=sum/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return fun(nums,sum,0,dp);
    }
};
