class Solution {
public:
    vector<int> getl(vector<int>& h,int n)
    {
        vector<int> k(n);
        k[0]=h[0];
        for(int i=1;i<n;i++)
        {
            k[i]=max(k[i-1],h[i]);
        }
        return k;
    }

    vector<int> getr(vector<int>& h,int n)
    {
        vector<int> k(n);
        k[n-1]=h[n-1];
        for(int i=n-2;i>=0;i--)
        {
            k[i]=max(k[i+1],h[i]);
        }
        return k;
    }

    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> lmax=getl(height,n);
        vector<int> rmax=getr(height,n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(lmax[i],rmax[i])-height[i];
        }
        return ans;
    }
};
