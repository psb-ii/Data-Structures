class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(),a.end(),greater<>());
        sort(b.begin(),b.end(),greater<>());
        set<pair<int,int>>se;
        vector<int>res;
        priority_queue<pair<int,pair<int,int>>>maxh;
        maxh.push({a[0]+b[0],{0,0}});
        se.insert({0,0});
        while(res.size() < k){
            int sum = maxh.top().first;
            int x = maxh.top().second.first;
            int y = maxh.top().second.second;
            res.push_back(sum);
            maxh.pop();
            if(x+1 < a.size() && se.find({x+1,y}) == se.end()){
                maxh.push({a[x+1]+b[y],{x+1,y}});
                se.insert({x+1,y});
            }
            if(y+1 < b.size() && se.find({x,y+1}) == se.end()){
                maxh.push({a[x]+b[y+1],{x,y+1}});
                se.insert({x,y+1});
            }
        }
        return res;
    }
};