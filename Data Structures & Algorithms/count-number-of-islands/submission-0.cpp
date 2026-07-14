class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>& visited,vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=1;
        vector<int> rdelta={-1,0,1,0};
        vector<int> cdelta={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+rdelta[i];
                int nc=c+cdelta[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]=='1')
                {
                    q.push({nr,nc});
                    visited[nr][nc]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    bfs(i,j,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
