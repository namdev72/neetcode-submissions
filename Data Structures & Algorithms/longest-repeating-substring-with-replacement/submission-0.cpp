class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();

        int l = 0;
        int r = 0;

        int ans = 0;
        int maxFreq = 0;

        vector<int> freq(26, 0);

        while (r < n) {

            freq[s[r] - 'A']++;

            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k) {

                freq[s[l] - 'A']--;

                // Recalculate max frequency
                maxFreq = 0;

                for (int x : freq)
                    maxFreq = max(maxFreq, x);

                l++;
            }

            ans = max(ans, r - l + 1);

            r++;
        }

        return ans;
    }
};