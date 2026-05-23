class Solution {
private: 
    int curr_time = 0;
    void dfs(int node,int parent,vector<int>&vis,vector<int>*adj,vector<int>&timein,vector<int>&lowest,vector<vector<int>>&res){
        vis[node] = 1;
        timein[node]=curr_time;
        lowest[node]=curr_time;
        curr_time++;
        for(auto it: adj[node]){
            if(it == parent)
                continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,timein,lowest,res);
                lowest[node] = min(lowest[it],lowest[node]);
                if(lowest[it] > timein[node]){
                    vector<int>v;
                    v.insert(v.end(),{node,it});
                    res.push_back(v);
                }
            }
            else{
                lowest[node] = min(lowest[it],lowest[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>vis(n,0);
        vector<int>adj[n];
        vector<int>timein(n,0);
        vector<int>lowest(n,0);
        vector<vector<int>>res;
        for(int i=0;i<connections.size();i=i+1){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<n;i=i+1){
            if(!vis[i]){
                dfs(i,-1,vis,adj,timein,lowest,res);
            }
        }
        return res;
    }
};