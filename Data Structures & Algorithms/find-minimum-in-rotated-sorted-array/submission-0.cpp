class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0;
        int h=nums.size()-1;
        int m;
        while(l<h)
        {
            m=l+(h-l)/2;
            if(nums[m]>nums[h]) l=m+1;
            else h=m;
        }
        return nums[l];
    }
};
