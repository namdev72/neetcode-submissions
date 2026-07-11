class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;
        for(auto i:s)
        {
            mpp1[i]++;
        }
        for(auto i:t)
        {
            mpp2[i]++;
        }
        for(auto i:mpp1)
        {
            if(mpp2.find(i.first)!=mpp2.end())
            {
                if(mpp2[i.first]!=i.second) return false;
            }else{
                return false;
            }
        }
        return true;

    }
};
