class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>indegrees(V,0);
        vector<int>adj[V];
        for(int i=0;i<edges.size();i=i+1){
            indegrees[edges[i][1]] +=1;
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        queue<int>qu;
        for(int i=0;i<V;i=i+1){
            if(!indegrees[i])
                qu.push(i);
        }
        vector<int>res;
        while(qu.size()){
            int node = qu.front();
            qu.pop();
            res.push_back(node);
            for(int i: adj[node]){
                indegrees[i] = indegrees[i] - 1;
                if(indegrees[i] == 0)
                    qu.push(i);
            }
        }
        if(res.size() != V){
            vector<int>k;
            return k;
        }
        return res;
    }
};