class Solution {
public:
    void fun(int idx,string& s,vector<vector<string>>& ans,vector<string>& path)
    {
        if(idx==s.length()){
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<s.length();i++)
        {
            if(ispalin(s,idx,i))
            {
                path.push_back(s.substr(idx,i-idx+1));
                fun(i+1,s,ans,path);
                path.pop_back();
            }
        }
    }

    bool ispalin(string& s,int i,int j){
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        fun(0,s,ans,path);
        return ans;
    }
};
