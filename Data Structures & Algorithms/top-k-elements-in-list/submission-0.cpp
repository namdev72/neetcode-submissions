class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> mpp;
        vector<pair<int, int>> arr;
        for(auto i:nums)
        {
            mpp[i]++;
        }
        for (const auto& p : mpp) {
            arr.push_back({p.second, p.first});
        }
         sort(arr.rbegin(), arr.rend());
        for(int i=0;i<k;i++)
        {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
