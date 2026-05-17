class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>vp[n+1];
        for(int i=0;i<times.size();i=i+1){
            vp[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>t(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        t[k]=0;
        minh.push({0,k});
        while(minh.size()){
            int current_time = minh.top().first;
            int node = minh.top().second;
            minh.pop();
            for(auto n:vp[node]){
                if(current_time + n.second < t[n.first]){
                    minh.push({current_time+n.second,n.first});
                    t[n.first]=current_time+n.second;
                }
            }
        }
        int res = INT_MIN;
        for(int i=1;i<=n;i=i+1){
            res = max(res,t[i]);
        }
        if(res != INT_MAX)
            return res;
        return -1;
    }
};