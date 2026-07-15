class Solution {
public:
    void bfs(queue<pair<int,int>>& q, vector<vector<bool>>& vis,
             vector<vector<int>>& heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<int> rdelta = {-1, 0, 1, 0};
        vector<int> cdelta = {0, 1, 0, -1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int nr = r + rdelta[k];
                int nc = c + cdelta[k];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   !vis[nr][nc] &&
                   heights[nr][nc] >= heights[r][c])
                {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<pair<int,int>> qp;
        queue<pair<int,int>> qa;

        // Pacific: Top row
        for(int j = 0; j < m; j++)
        {
            qp.push({0, j});
            pacific[0][j] = true;
        }

        // Pacific: Left column
        for(int i = 1; i < n; i++)
        {
            qp.push({i, 0});
            pacific[i][0] = true;
        }

        // Atlantic: Bottom row
        for(int j = 0; j < m; j++)
        {
            qa.push({n - 1, j});
            atlantic[n - 1][j] = true;
        }

        // Atlantic: Right column
        for(int i = 0; i < n - 1; i++)
        {
            qa.push({i, m - 1});
            atlantic[i][m - 1] = true;
        }

        bfs(qp, pacific, heights);
        bfs(qa, atlantic, heights);

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};