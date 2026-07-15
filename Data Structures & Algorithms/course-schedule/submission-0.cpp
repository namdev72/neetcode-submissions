class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> indegree(n,0);
        for(auto it:prerequisites)
        {
            indegree[it[0]]++;
        }
        queue<int> q;
        //with all 0 to q
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        vector<int> order;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            order.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        if(order.size()==n) return true;
        return false;
    }
};
