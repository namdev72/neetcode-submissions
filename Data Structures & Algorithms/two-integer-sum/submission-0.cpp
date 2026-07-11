class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int check=target-nums[i];
            if(mpp.find(check)!=mpp.end())
            {
                 ans.push_back(mpp[check]);
                ans.push_back(i);
               
                return ans;
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};
