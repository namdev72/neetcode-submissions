class Solution {
public:
    void solve(int c,vector<string>& board,vector<vector<string>>& ans,vector<int>& leftrow
    ,vector<int>& udiagonal, vector<int>& ldiagonal,int n)
    {
        if(c==n)
        {
            ans.push_back(board);
            return;
        }
        for(int r=0;r<n;r++)
        {
            if(leftrow[r]==0 && udiagonal[n-1+c-r]==0 && ldiagonal[r+c]==0)
            {
                board[r][c]='Q';
                leftrow[r]=1;
                udiagonal[n-1+c-r]=1;
                ldiagonal[r+c]=1;
                solve(c+1,board,ans,leftrow,udiagonal,ldiagonal,n);
                leftrow[r]=0;
                udiagonal[n-1+c-r]=0;
                ldiagonal[r+c]=0;
                board[r][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int> leftrow(n,0);
        vector<int> udiagonal(2*n-1,0);
        vector<int> ldiagonal(2*n-1,0);
        solve(0,board,ans,leftrow,udiagonal,ldiagonal,n);
        return ans;
    }
};
