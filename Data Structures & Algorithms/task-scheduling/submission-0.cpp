class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26,0);
        for(auto c:tasks)
        {
            f[c-'A']++;
        }

        priority_queue<int> pq;
        for(auto it:f)
        {
            if(it>0) pq.push(it);
        }

        int count=0;
        while(!pq.empty())
        {
            vector<int> temp;
            for(int i=1;i<=n+1;i++)
            {
                if(!pq.empty()){
                    int fre=pq.top();
                    pq.pop();
                    fre--;
                    temp.push_back(fre);
                }
            }
            for(auto it:temp)
            {
                if(it>0) pq.push(it);
            }
            if(pq.empty())
            {
                count+=temp.size();
            }else{
                count+=n+1;
            }

        }
        return count;
    }
};
