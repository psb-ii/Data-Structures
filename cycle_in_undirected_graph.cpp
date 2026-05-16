class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>vis(V,0);
        vector<int>adj[V];
        for(int i=0;i<edges.size();i=i+1){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<V;i=i+1){
            if(!vis[i]){
                queue<pair<int,int>>qu;
                qu.push({i,-1});
                vis[i]=1;
                while(qu.size()){
                    int node = qu.front().first;
                    int parent = qu.front().second;
                    qu.pop();
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            vis[it] = true;
                            qu.push({it,node});
                        }
                        else
                        if(it != parent){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};