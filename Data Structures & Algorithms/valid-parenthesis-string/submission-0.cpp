class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int i=0;
        int low=0;
        int high=0;
        while(i<n)
        {
            if(s[i]=='('){
                low++;
                high++;
            }
            else if(s[i]==')')
            {
                low--;
                high--;
            }else{
                low--;
                high++;;
            }
            if(low<0) low=0;
            if(high<0) return false;
            i++;
        }
        return low==0;
    }
    
};
