class Solution {
public:

    int table(vector<int>& nums, int idx, int end) {

        vector<int> dp(end + 3, 0);

        for (int i = end; i >= idx; i--) {

            int take = nums[i] + dp[i + 2];
            int notake = dp[i + 1];

            dp[i] = max(take, notake);
        }

        return dp[idx];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(
            table(nums, 0, n - 2),  // exclude last
            table(nums, 1, n - 1)   // exclude first
        );
    }
};