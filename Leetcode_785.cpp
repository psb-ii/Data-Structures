class Solution {
private:
    bool check(int node,vector<int>&colour,int curr,vector<vector<int>>&graph){
        colour[node] = curr;
        for(auto it : graph[node]){
            if(colour[it] == -1){
                if(!check(it,colour,1-curr,graph))
                    return false;
            }
            else
            if(colour[it] == curr){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>colour(graph.size(),-1);
        for(int i=0;i<graph.size();i=i+1){
            if(colour[i] == -1){
                if(!check(i,colour,0,graph))
                    return false;
            }
        }
        return true;
    }
};