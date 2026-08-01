class Solution {
public:
    void fun(vector<string>& ans,string str,int o,int c,int n)
    {
        //base case
        if(str.length()==n*2)
        {
            ans.push_back(str);
            return;
        }
        if(o<n)
        {
            str+="(";
            fun(ans,str,o+1,c,n);
            str.pop_back();
        }
        if(c<o)
        {
            str+=")";
            fun(ans,str,o,c+1,n);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fun(ans,"",0,0,n);
        return ans;
    }
};
