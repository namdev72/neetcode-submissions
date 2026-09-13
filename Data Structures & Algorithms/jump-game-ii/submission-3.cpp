class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int l=0;
        int r=0;
        while(r<n-1)
        {
            int far=r;
            for(int i=l;i<=r;i++)
            {
                far=max(far,i+nums[i]);
            }
            l=r+1;
            r=far;
            count++;
        }
        return count;
    }
};
