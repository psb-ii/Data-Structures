class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        int i=0;
        int j=0;
        vector<int>res;
        for(i=0;i<k;i=i+1){
            while(dq.size() && dq.back().first <= nums[i])
                dq.pop_back();
            dq.push_back({nums[i],i});
        }
        res.push_back(dq.front().first);
        for(i=k,j=1;i<nums.size();i=i+1,j=j+1){
            while(dq.size() && dq.front().second < j)
                dq.pop_front();
            while(dq.size() && dq.back().first <= nums[i])
                dq.pop_back();
            dq.push_back({nums[i],i});
            res.push_back(dq.front().first);
        }
        return res;
    }
};