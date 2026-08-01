class Solution {
public:
    void fun(int i,vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        //take;
        temp.push_back(nums[i]);
        fun(i+1,nums,ans,temp);

        //not take
        temp.pop_back();
        fun(i+1,nums,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(0,nums,ans,temp);
        return ans;
    }
};
