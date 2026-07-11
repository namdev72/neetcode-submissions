class Solution {
public:

    bool isan(string s,string t)
    {
        if(s.size()!=t.size()) return false;

        vector<int> freq(26,0);

        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        for(int x:freq)
            if(x!=0)
                return false;

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;

        vector<int> visited(strs.size(),-1);

        for(int i=0;i<strs.size();i++)
        {
            if(visited[i]==-1)
            {
                vector<string> temp;

                temp.push_back(strs[i]);

                visited[i]=1;

                for(int j=i+1;j<strs.size();j++)
                {
                    if(visited[j]==-1)
                    {
                        if(isan(strs[i],strs[j]))
                        {
                            temp.push_back(strs[j]);
                            visited[j]=1;
                        }
                    }
                }

                ans.push_back(temp);
            }
        }

        return ans;
    }
};