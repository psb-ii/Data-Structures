class Solution {
  private:
    void giveThePossibleOrder(int node,vector<int>&vis,stack<int>&st,vector<int>*adj){
        vis[node] = 1;
        for(auto n: adj[node]){
            if(!vis[n])
                giveThePossibleOrder(n,vis,st,adj);
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(int i=0;i<edges.size();i=i+1){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        stack<int>st;
        vector<int>res;
        vector<int>vis(V,0);
        for(int i=0;i<V;i=i+1){
            if(!vis[i]){
                giveThePossibleOrder(i,vis,st,adj);
            }
        }
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        if(res.size() < V){
            vector<int>k;
            return k;
        }
        return res;
    }
};