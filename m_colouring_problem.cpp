class Solution {
private:
    bool isSafe(int node,int colour,vector<vector<int>>&adj,vector<int>&colours){
        for(int neighbour : adj[node]){
            if(colours[neighbour] == colour)
                return false;
        }
        return true;
    }
    bool isPossible(int nodes,int colour,vector<vector<int>>&adj,vector<int>&colours){
        for(int i=0;i<nodes;i=i+1){
            if(colours[i] == -1){
                for(int j=0;j<colour;j=j+1){
                    if(isSafe(i,j,adj,colours)){
                        colours[i] = j;
                        if(isPossible(nodes,colour,adj,colours))
                            return true;
                        colours[i] = -1;
                    }
                }
                return false;
            }
        }
        return true;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>>adj(v);
        for(int i=0;i<edges.size();i=i+1){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int>colours(v,-1);
        return isPossible(v,m,adj,colours);
    }
};