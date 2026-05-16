class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>>adj[V];
        for(int i=0;i<edges.size();i=i+1){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        set<pair<int,int>>se; //{dist,node}
        vector<int>dis(V,1e9);
        dis[src]=0;
        se.insert({0,src});
        while(!se.empty()){
            auto it=*(se.begin());
            int node=it.second;
            int current_dis=it.first;
            se.erase(it);
            for(auto iter: adj[node]){
                if(current_dis + iter.second < dis[iter.first]){
                    if(dis[iter.first] != 1e9)
                        se.erase({dis[iter.first],iter.first});
                    se.insert({current_dis + iter.second,iter.first});
                    dis[iter.first] = current_dis + iter.second;
                } 
            }
        }
        return dis;
    }
};