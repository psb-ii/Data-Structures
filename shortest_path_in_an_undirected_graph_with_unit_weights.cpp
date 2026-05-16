class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<int>adj[V];
        for(int i=0;i<edges.size();i=i+1){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(V,0);
        vector<int>dist(V,-1);
        queue<int>qu;
        qu.push(src);
        vis[src]=1;
        int level=0;
        while(qu.size()){
            int si = qu.size();
            for(int i=0;i<si;i=i+1){
                int node = qu.front();
                qu.pop();
                dist[node]=level;
                for(auto n:adj[node]){
                    if(!vis[n]){
                        vis[n]=1;
                        qu.push(n);
                    }
                }
            }
            level +=1;
        }
        return dist;
    }
};
