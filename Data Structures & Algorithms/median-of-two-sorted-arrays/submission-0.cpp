class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> arr;

        for(int x : nums1)
            arr.push_back(x);

        for(int x : nums2)
            arr.push_back(x);

        sort(arr.begin(), arr.end());

        int total = arr.size();

        if(total % 2 == 1)
        {
            return arr[total/2];
        }
        else
        {
            return (arr[total/2 - 1] + arr[total/2]) / 2.0;
        }
    }
};