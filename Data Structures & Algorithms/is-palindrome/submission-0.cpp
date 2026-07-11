class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int f=0;
        int e=n-1;
        while(f<e)
        {
            while (f < e && !isalnum(s[f])) f++;
            while (f < e && !isalnum(s[e])) e--;
            if(tolower(s[f])!=tolower(s[e])) return false;
            f++;
            e--;
        }
        return true;
    }
};
