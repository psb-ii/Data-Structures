class MedianFinder {
private:
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxh.push(num);
        if(maxh.size() - minh.size() > 1){
            minh.push(maxh.top());
            maxh.pop();
        }
        if(minh.size() && maxh.size()){
            if(minh.top() < maxh.top()){
                int mini = minh.top();
                int maxi = maxh.top();
                minh.pop();
                maxh.pop();
                minh.push(maxi);
                maxh.push(mini);
            }
        }
    }
    
    double findMedian() {
        if(maxh.size() == minh.size())
            return (1.0*(maxh.top()+minh.top())) / 2;
        return 1.0*maxh.top();
    }
};