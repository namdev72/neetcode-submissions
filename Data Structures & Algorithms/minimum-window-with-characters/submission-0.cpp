class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) return "";

        map<char,int> mpp;

        for (char c : t)
            mpp[c]++;

        int l = 0;
        int count = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.size(); r++) {

            if (mpp[s[r]] > 0)
                count++;

            mpp[s[r]]--;

            while (count == t.size()) {

                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                mpp[s[l]]++;

                if (mpp[s[l]] > 0)
                    count--;

                l++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};