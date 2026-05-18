class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>>adj[V];
        for(int i=0;i<edges.size();i=i+1){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>vis(V,0);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minh;
        minh.push({0,{0,-1}});
        int res = 0;
        while(minh.size()){
            int wt = minh.top().first;
            int node = minh.top().second.first;
            int par = minh.top().second.second;
            minh.pop();
            if(!vis[node] && par != -1)
                res +=wt;
            if(!vis[node]){
                vis[node] = 1;
            }
            for(auto n: adj[node]){
                if(!vis[n.first])
                    minh.push({n.second,{n.first,node}});
            }
        }
        return res;
    }
};