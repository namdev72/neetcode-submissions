class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mpp;
        int n=s.size();
        vector<int> nextoccur(n);
        for(int i=n-1;i>=0;i--)
        {
            char c=s[i];
            if(mpp.find(c)!=mpp.end())
            {
                nextoccur[i]=mpp[c];
            }
            else{
                nextoccur[i]=-1;
            }
            mpp[c]=i;
        }
        vector<int> ans;
        int start = 0;
        int maxrange = -1;

        for(int i = 0; i < n; i++) {

            maxrange = max(maxrange, i);

            if(nextoccur[i] != -1)
               maxrange = max(maxrange, nextoccur[i]);

            if(maxrange == i) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
