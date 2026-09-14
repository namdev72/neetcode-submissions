class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n=inter.size();
        if(n==0) return {};
        sort(inter.begin(),inter.end());
        vector<vector<int>> ans;
        vector<int> temp=inter[0];
        for(int i=1;i<n;i++)
        {
            //overlap
            if(temp[1]>=inter[i][0])
            {
                temp[0]=min(temp[0],inter[i][0]);
                temp[1]=max(temp[1],inter[i][1]);
            }
            //non overlap
            else{
                ans.push_back(temp);
                temp=inter[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
