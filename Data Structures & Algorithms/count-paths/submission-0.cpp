class Solution {
public:
    int fun(int i,int j,int m,int n,vector<vector<int>>& dp)
    {
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=fun(i,j+1,m,n,dp);
        int down=fun(i+1,j,m,n,dp);
        return dp[i][j]=right+down;
    }
    int table(int m,int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int right=dp[i][j+1];
                int down=dp[i+1][j];
                dp[i][j]+=right+down;
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        //vector<vector<int>> dp(m,vector<int>(n,-1));
        //return fun(0,0,m,n,dp);
        return table(m,n);
    }
};
