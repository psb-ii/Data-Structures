class Solution {
private:
    bool detect(int node,vector<int>*adj,vector<int>&vis,vector<int>&pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto n: adj[node]){
            if(!vis[n]){
                if(detect(n,adj,vis,pathVis) == true)
                    return true;
            }
            else
            if(pathVis[n])
                return true;
        }
        pathVis[node] = 0;
        return false;
    }
    void topo(int node,vector<int>*adj,vector<int>&vis,stack<int>&st){
        vis[node] = 1;
        for(auto n: adj[node]){
            if(!vis[n]){
                topo(n,adj,vis,st);
            }
        }
        st.push(node);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<int>pathVis(numCourses,0);
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i=i+1){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>res;
        for(int i=0;i<numCourses;i=i+1){
            if(!vis[i]){
                if(detect(i,adj,vis,pathVis))
                    return res;
            }
        }
        stack<int>st;
        for(int i=0;i<numCourses;i=i+1){
            vis[i]=0;
        }
        for(int i=0;i<numCourses;i=i+1){
            if(!vis[i]){
                topo(i,adj,vis,st);
            }
        }
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};