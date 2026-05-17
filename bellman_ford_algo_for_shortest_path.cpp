// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dis(V,INT_MAX);
        dis[src]=0;
        for(int i=0;i<V-1;i=i+1){
            for(int j=0;j<edges.size();j=j+1){
                if(dis[edges[j][0]] != INT_MAX && dis[edges[j][0]] + edges[j][2] < dis[edges[j][1]])
                    dis[edges[j][1]]=dis[edges[j][0]] + edges[j][2];  
            }
        }
        for(int i=0;i<edges.size();i=i+1){
            if(dis[edges[i][0]] != INT_MAX && dis[edges[i][0]] + edges[i][2] < dis[edges[i][1]]){
                vector<int>res(1,-1);
                return res;
            }
        }
        for(int i=0;i<V;i=i+1){
            if(dis[i] == INT_MAX)
                dis[i] = 1e8;
        }
        return dis;
    }
};
