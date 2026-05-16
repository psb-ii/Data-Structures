class Solution {
private:
    bool detectCycle(int node,vector<int>*adj,vector<int>&vis,vector<int>&pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(detectCycle(it,adj,vis,pathVis))
                    return true;
            }
            else
            if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<int>pathVis(numCourses,0);
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i=i+1){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i=i+1){
            if(!vis[i]){
                if(detectCycle(i,adj,vis,pathVis)){
                    return false;
                }
            }
        }
        return true;
    }
};