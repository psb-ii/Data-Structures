// User function Template for C++
class Solution {
  private:
    void dfsTraversal(int node,vector<pair<int,int>>*adj,vector<int>&vis,stack<int>&st){
        vis[node]=1;
        for(auto n:adj[node]){
            if(!vis[n.first])
                dfsTraversal(n.first,adj,vis,st);
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>>adj[V];
        for(int i=0;i<edges.size();i=i+1){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0;i<V;i=i+1){
            if(!vis[i])
                dfsTraversal(i,adj,vis,st);
        }
        vector<int>dist(V,1e8);
        dist[0]=0;
        while(st.size()){
            int node = st.top();
            st.pop();
            for(auto n: adj[node]){
                if(dist[node] + n.second < dist[n.first])
                    dist[n.first] = dist[node] + n.second;
            }
        }
        for(int i=0;i<V;i=i+1){
            if(dist[i] >= 1e8)
                dist[i]=-1;
        }
        return dist;
    }
};
