class Solution {
private:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        priority_queue<int,vector<int>,greater<int>>minh;
        vector<pair<int,int>>vp;
        for(int i=0;i<deadline.size();i=i+1){
            vp.push_back({deadline[i],profit[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        for(int i=0;i<vp.size();i=i+1){
            minh.push(vp[i].second);
            if(minh.size() > vp[i].first)
                minh.pop();
        }
        vector<int>max_jobs;
        max_jobs.push_back(minh.size());
        int max_profit = 0;
        while(minh.size()){
            max_profit +=minh.top();
            minh.pop();
        }
        max_jobs.push_back(max_profit);
        return max_jobs;
    }
};