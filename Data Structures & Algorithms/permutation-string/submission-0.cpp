class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if(n > m)
            return false;

        vector<int> f1(26,0), f2(26,0);

        for(char c : s1)
            f1[c-'a']++;

        for(int i=0;i<m;i++)
        {
            f2[s2[i]-'a']++;

            if(i >= n)
                f2[s2[i-n]-'a']--;

            if(f1 == f2)
                return true;
        }

        return false;
    }
};