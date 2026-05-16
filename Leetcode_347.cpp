class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>ma;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        for(int i=0;i<nums.size();i=i+1){
            ma[nums[i]]++;
        }
        for(auto it=ma.begin();it!=ma.end();it++){
            minh.push({it->second,it->first});
            if(minh.size() > k)
                minh.pop();
        }
        vector<int>frequents;
        while(minh.size()){
            frequents.emplace_back(minh.top().second);
            minh.pop();
        }
        return frequents;
    }
};