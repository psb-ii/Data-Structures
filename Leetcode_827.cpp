class DisjointSet{
    vector<int>rank;
    vector<int>parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i=i+1){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulpar_u = findParent(u);
        int ulpar_v = findParent(v);
        if(ulpar_u == ulpar_v)
            return;
        if(rank[ulpar_u] < rank[ulpar_v]){
            parent[ulpar_u] = ulpar_v;
        }
        else
        if(rank[ulpar_v] < rank[ulpar_u]){
            parent[ulpar_v] = ulpar_u;
        }
        else{
            parent[ulpar_u] = ulpar_v;
            rank[ulpar_v] = rank[ulpar_u];
        }
    }
    void unionBySize(int u,int v){
        int ulpar_u = findParent(u);
        int ulpar_v = findParent(v);
        if(rank[ulpar_u] < rank[ulpar_v]){
            rank[ulpar_v] = rank[ulpar_v] + rank[ulpar_u];
            parent[ulpar_u] = ulpar_v;
        }
        else{
            rank[ulpar_u] = rank[ulpar_u] + rank[ulpar_v];
            parent[ulpar_v] = ulpar_u;
        }
    }
    int findRank(int u){
        return rank[u];
    }
};
class Solution {
private:
    bool isValidCoordinateOrNot(int abs,int ord,vector<vector<int>>&grid){
        if(abs >= 0 && abs < grid.size() && ord >= 0 && ord < grid[abs].size())
            return true;
        return false;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        int n = grid.size();
        int m = grid[0].size();
        int count = n*m;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        DisjointSet obj(count);
        for(int i=0;i<grid.size();i=i+1){
            for(int j=0;j<grid[i].size();j=j+1){
                int abs = i;
                int ord = j;
                int u = abs*grid.size() + ord;
                if(grid[abs][ord]){
                    for(int k=0;k<4;k=k+1){
                        vis[abs][ord]=1;
                        int new_abs = abs + dx[k];
                        int new_ord = ord + dy[k];
                        if(isValidCoordinateOrNot(new_abs,new_ord,grid) && grid[new_abs][new_ord]){
                            vis[new_abs][new_ord]=1;
                            int v = new_abs * grid.size() + new_ord;
                            obj.unionBySize(u,v);
                        }
                    }
                }
            }
        }
        int maxi = 1;
        unordered_map<int,int>ma;
        for(int i=0;i<count;i=i+1){
            int ulpar_u = obj.findParent(i);
            ma[ulpar_u]++;
        }
        for(auto it=ma.begin();it!=ma.end();it++){
            maxi = max(maxi,ma[it->first]);
        }
        for(int i=0;i<grid.size();i=i+1){
            for(int j=0;j<grid[i].size();j=j+1){
                if(!grid[i][j]){
                    int abs = i;
                    int ord = j;
                    int u = abs*grid[abs].size() + ord;
                    unordered_set<int>se;
                    int curr_maxi = 1;
                    for(int k=0;k<4;k=k+1){
                        int new_abs = abs + dx[k];
                        int new_ord = ord + dy[k];
                        if(isValidCoordinateOrNot(new_abs,new_ord,grid) && grid[new_abs][new_ord]){
                            int v = new_abs*grid[new_abs].size() + new_ord;
                            int ulpar_u = obj.findParent(v);
                            if(se.find(ulpar_u) == se.end()){
                                int island_size = ma[ulpar_u];
                                curr_maxi = curr_maxi + island_size;
                                se.insert(ulpar_u);
                            }
                        }
                    }
                    se.clear();
                    maxi = max(maxi,curr_maxi);
                }
            }
        }
        return maxi;
    }
};