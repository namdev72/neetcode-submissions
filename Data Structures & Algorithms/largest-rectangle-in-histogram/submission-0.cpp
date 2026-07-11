class Solution {
public:
    vector<int> preSmall(vector<int>& height)
    {
        int n=height.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && height[st.top()]>=height[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            else ans[i]=-1;
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmall(vector<int>& height)
    {
        int n=height.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && height[st.top()]>=height[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            else ans[i]=n;
            st.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse=preSmall(heights);
        vector<int> nse=nextSmall(heights);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};