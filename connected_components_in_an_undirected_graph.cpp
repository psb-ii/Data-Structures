class Solution {
  private:
    void dfsTraverse(int node,vector<int>&component,vector<int>*adj,vector<bool>&vis){
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=true;
                component.push_back(it);
                dfsTraverse(it,component,adj,vis);
            }
        }
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(int i=0;i<edges.size();i=i+1){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>>components;
        vector<bool>vis(V+1,false);
        for(int i=0;i<V;i=i+1){
            if(!vis[i]){
                vis[i]=true;
                vector<int>component;
                component.push_back(i);
                dfsTraverse(i,component,adj,vis);
                components.push_back(component);
            }
        }
        return components;
    }
};
 