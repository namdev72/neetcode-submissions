class KthLargest {
public:
   // vector<int> arr;
    priority_queue<int,vector<int>,greater<int>> p;
    int k;
    KthLargest(int k, vector<int>& nums) {
        //this->arr=nums;
        this->k=k;
        for(auto it:nums)
        {
            p.push(it);
            if(p.size()>k) p.pop();
        }
    }
    
    int add(int val) {
        p.push(val);
        if(p.size()>k) p.pop();
        return p.top();

    }
};
