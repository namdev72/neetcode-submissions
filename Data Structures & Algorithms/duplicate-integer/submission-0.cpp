class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> mpp;
        for(auto i:nums)
        {
            mpp[i]++;
        }
        for(auto i:mpp)
        {
            if(i.second>1) return true;
        }
        return false;
        
    }
};