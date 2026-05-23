// User function Template for C++

class Solution {
  private:
    int curr_time = 0;
    void dfs(int node,int parent,vector<int>&vis,vector<int>*adj,vector<int>&timein,vector<int>&lowest,vector<int>&isArticulate){
        vis[node]=1;
        timein[node]=curr_time;
        lowest[node]=curr_time;
        curr_time++;
        int child = 0;
        for(auto it: adj[node]){
            if(it == parent)
                continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,timein,lowest,isArticulate);
                lowest[node] = min(lowest[node],lowest[it]);
                if(lowest[it] >= timein[node] && parent != -1){
                    isArticulate[node] = 1;
                }
                child = child + 1;
            }
            else{
                lowest[node] = min(lowest[node],timein[it]);
            }
        }
        if(child > 1 && parent < 0){
            isArticulate[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        vector<int>timein(V,0);
        vector<int>lowest(V,0);
        vector<int>isArticulate(V,0);
        for(int i=0;i<V;i=i+1){
            if(!vis[i]){
                dfs(i,-1,vis,adj,timein,lowest,isArticulate);
            }
        }
        vector<int>res;
        for(int i=0;i<V;i=i+1){
            if(isArticulate[i] == 1)
                res.push_back(i);
        }
        if(res.size() == 0)
            res.insert(res.end(),-1);
        return res;
    }
};