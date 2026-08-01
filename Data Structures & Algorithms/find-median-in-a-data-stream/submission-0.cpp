class MedianFinder {
public:
    vector<int> arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
    }
    
    double findMedian() {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(n%2==1)
        {
            return arr[n/2];
        }else{
            int s=arr[n/2];
            int f=arr[n/2-1];
            return (f+s)/2.0;
        }
    }
};
