class Solution {
private:
    bool findEventualSafeStates(int node,vector<int>&vis,vector<int>&pathvis,vector<int>&marked,vector<vector<int>>&graph){
        vis[node]=1;
        pathvis[node]=1;
        marked[node]=0;
        for(auto n:graph[node]){
            if(!vis[n]){
                if(findEventualSafeStates(n,vis,pathvis,marked,graph))
                    return true;
            }
            else
            if(pathvis[n])
                return true;
        }
        pathvis[node]=0;
        marked[node]=1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),0);
        vector<int>pathvis(graph.size(),0);
        vector<int>marked(graph.size());
        vector<int>res;
        for(int i=0;i<graph.size();i=i+1){
            if(!vis[i])
                bool flag = findEventualSafeStates(i,vis,pathvis,marked,graph);
        }
        for(int i=0;i<marked.size();i=i+1){
            if(marked[i])
                res.push_back(i);
        }
        return res;
    }
};