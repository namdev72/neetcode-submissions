class Solution {
public:
    void fun(int idx,string s,string& ans)
    {
        if(idx==s.length()) return;
        for(int i=idx;i<s.length();i++)
        {
            if(ispalid(s,idx,i))
            {
                if(ans.length()<=i-idx+1)
                {
                    ans=s.substr(idx,i-idx+1);
                    fun(idx+1,s,ans);
                }
            }
        }
    }

    bool ispalid(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans;
        fun(0,s,ans);
        return ans;
    }
};
