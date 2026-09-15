class Solution {
public:
    bool fun(string s,unordered_set<string>& st,int idx,int n,vector<int>& dp)
    {
        if(idx>=n) return true;
        if(st.find(s)!=st.end()) return true;
        if(dp[idx]!=-1) return dp[idx];
        for(int l=1;l<n;l++)
        {
            string temp=s.substr(idx,l);
            if(st.find(temp)!=st.end())
            {
                if(fun(s,st,idx+l,n,dp)) return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& word) {
        unordered_set<string> st;
        for(auto& it:word)
        {
            st.insert(it);
        }
        int n=s.length();
        vector<int> dp(n,-1);
        return fun(s,st,0,n,dp);
    }
};
