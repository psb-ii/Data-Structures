// User function Template for C++
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
};
class Solution {
  private:
    bool isValidCoordinateOrNot(int n,int m,int abs,int ord){
        if(abs >= 0 && abs < n && ord >= 0 && ord < m)
            return true;
        return false;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int>res;
        int island_count = 0;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        int total = n*m;
        DisjointSet obj(total);
        for(int i=0;i<operators.size();i=i+1){
            int abs = operators[i][0];
            int ord = operators[i][1];
            if(!vis[abs][ord]){
                island_count++;
                int u = abs*m + ord;
                vis[abs][ord]=1;
                for(int i=0;i<4;i=i+1){
                    int new_abs = abs + dx[i];
                    int new_ord = ord + dy[i];
                    if(isValidCoordinateOrNot(n,m,new_abs,new_ord) && vis[new_abs][new_ord]){
                        int v = new_abs*m + new_ord;
                        int ulpar_u = obj.findParent(u);
                        int ulpar_v = obj.findParent(v);
                        if(ulpar_u != ulpar_v){
                            island_count--;
                            obj.unionByRank(u,v);
                        }
                    }
                }
                res.push_back(island_count);
            }
            else
                res.push_back(island_count);
        }
        return res;
    }
};
