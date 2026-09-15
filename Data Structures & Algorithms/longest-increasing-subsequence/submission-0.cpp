class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int cur=n-1;cur>=0;cur--)
        {
            for(int pre=cur-1;pre>=-1;pre--)
            {
                int take=0;
                if(pre==-1 || nums[cur]>nums[pre])
                {
                    take=1+dp[cur+1][cur+1];
                }
                int notake=0+dp[cur+1][pre+1];
                dp[cur][pre+1]=max(take,notake);
            }
        }
        return dp[0][0];
    }
};
