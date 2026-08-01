class Solution {
public:
    void fun(int i,vector<int>& nums,int target,vector<vector<int>>& ans,vector<int>& temp)
    {
        if(i==nums.size())
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        if(nums[i]<=target){
        temp.push_back(nums[i]);
        fun(i,nums,target-nums[i],ans,temp);
        temp.pop_back();
        }
        
        fun(i+1,nums,target,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(0,nums,target,ans,temp);
        return ans;
    }
};
