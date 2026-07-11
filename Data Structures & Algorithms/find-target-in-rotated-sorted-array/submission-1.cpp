class Solution {
public:

    int fun(vector<int>& nums)
    {
        int l = 0;
        int h = nums.size() - 1;

        while(l < h)
        {
            int m = l + (h - l) / 2;

            if(nums[m] > nums[h])
                l = m + 1;
            else
                h = m;
        }

        return l;
    }

    int find(vector<int>& nums, int l, int h, int target)
    {
        while(l <= h)
        {
            int m = l + (h - l) / 2;

            if(nums[m] == target)
                return m;

            if(nums[m] < target)
                l = m + 1;
            else
                h = m - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target)
    {
        int n = nums.size();

        int pivot = fun(nums);

        int ans = find(nums, 0, pivot - 1, target);

        if(ans != -1)
            return ans;

        return find(nums, pivot, n - 1, target);
    }
};