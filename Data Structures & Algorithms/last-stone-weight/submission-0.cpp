class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //default it is in max heap
        priority_queue<int> p;
        for(auto it:stones)
        {
            p.push(it);
        }
        while(p.size()>1)
        {
            int f=p.top();
            p.pop();
            int s=p.top();
            p.pop();
            p.push(f-s);
        }
        return p.top();
    }
};
