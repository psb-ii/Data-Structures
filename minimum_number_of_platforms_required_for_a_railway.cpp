class Solution {
private:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        vector<pair<int,int>>vp;
        for(int i=0;i<arr.size();i=i+1){
            vp.push_back({arr[i],dep[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        int min_possible = 1;
        int prev = 0;
        int res = 1;
        priority_queue<int,vector<int>,greater<int>>minh;
        for(int i=0;i<vp.size();i=i+1){
            minh.push(vp[i].second);
            while(minh.size() && minh.top() < vp[i].first){
                minh.pop();
            }
            if(minh.size() > res)
                res = minh.size();
        }
        return res;
    }
};