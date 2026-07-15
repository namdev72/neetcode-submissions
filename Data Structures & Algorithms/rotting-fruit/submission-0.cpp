class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int ans=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        vector<int> rdelta={-1,0,1,0};
        vector<int> cdelta={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int count=q.front().second;
            ans=max(ans,count);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+rdelta[i];
                int nc=c+cdelta[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]==1)
                {
                    visited[nr][nc]=1;
                    q.push({{nr,nc},count+1});
                    grid[nr][nc]=2;
                }
            }
    
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};
