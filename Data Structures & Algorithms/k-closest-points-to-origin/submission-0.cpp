class Solution {
public:
//min heap
    bool cmp(auto& a,auto& b)
    {
        return a.first>b.first;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority_queue<pair<double,pair<int,int>>,
        // vector<pair<double,pair<int,int>>>,
        // cmp
        // > p;
        priority_queue<pair<double,pair<int,int>>,
        vector<pair<double,pair<int,int>>>,
        greater<pair<double,pair<int,int>>>
        > p;
        for(auto pt:points)
        {
            int x=pt[0];
            int y=pt[1];
            double dis=sqrt((x*x)+(y*y));
            p.push({dis,{pt[0],pt[1]}});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++)
        {
            auto point=p.top();
            int x=point.second.first;
            int y=point.second.second;
            ans.push_back({x,y});
            p.pop();
        }
        return ans;

        
    }
};
