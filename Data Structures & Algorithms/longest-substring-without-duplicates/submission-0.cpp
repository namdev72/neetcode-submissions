class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0;
        unordered_set<char> st;
        int r=0;
        int maxilen=0;
        while(r<n)
        {
            if(!st.count(s[r]))
            {
                st.insert(s[r]);
                r++;
                maxilen=max(maxilen,r-l);
            }
            else{
                while(st.count(s[r]))
                {
                    st.erase(s[l]);
                    l++;
                }
            }
        }
        return maxilen;
    }
};
