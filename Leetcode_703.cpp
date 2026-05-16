class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>minh;
    int si;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i=i+1){
            minh.push(nums[i]);
            if(minh.size() > k)
                minh.pop();
        }
        si = k;
    }
    
    int add(int val) {  
        minh.push(val);
        if(minh.size() > si)
            minh.pop();
        return minh.top();
    }
};