class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int nodes = isConnected.size();
        vector<bool>vis(nodes+1,false);
        vector<int>adj[nodes+1];
        for(int i=0;i<isConnected.size();i=i+1){
            for(int j=0;j<isConnected[i].size();j=j+1){
                if(isConnected[i][j] && i != j)
                    adj[i+1].push_back(j+1);
            }
        }
        queue<int>qu;
        int provinces = 0;
        for(int i=1;i<=nodes;i=i+1){
            if(!vis[i]){
                provinces++;
                vis[i] = true;
                qu.push(i);
                while(qu.size()){
                    int node = qu.front();
                    qu.pop();
                    for(int it : adj[node]){
                        if(!vis[it]){
                            vis[it] = true;
                            qu.push(it);
                        }
                    }
                }
            }
        }
        return provinces;
    }
};