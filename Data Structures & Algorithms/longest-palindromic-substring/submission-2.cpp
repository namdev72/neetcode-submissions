class Solution {
public:
    bool check(string& s, int i, int j, vector<vector<int>>& dp)
    {
        if(i >= j)
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] != s[j])
        {
            return dp[i][j] = 0;
        }

        return dp[i][j] = check(s, i + 1, j - 1, dp);
    }

    string longestPalindrome(string s)
    {
        int n = s.length();

        string ans = "";

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(check(s, i, j, dp))
                {
                    if(ans.length() < j - i + 1)
                    {
                        int len = j - i + 1;
                        ans = s.substr(i, len);
                    }
                }
            }
        }

        return ans;
    }
};