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
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,pair<int,int>>>vp;
        for(int i=0;i<edges.size();i=i+1){
            vp.push_back({edges[i][2],{edges[i][0],edges[i][1]}});
        }
        sort(vp.begin(),vp.end());
        int res = 0;
        DisjointSet obj(V);
        for(int i=0;i<edges.size();i=i+1){
            int ulpar_u = obj.findParent(vp[i].second.first);
            int ulpar_v = obj.findParent(vp[i].second.second);
            if(ulpar_v != ulpar_u){
                res = res + vp[i].first;
            }
            obj.unionBySize(vp[i].second.first,vp[i].second.second);
        }
        return res;
    }
};class DisjointSet{
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
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,pair<int,int>>>vp;
        for(int i=0;i<edges.size();i=i+1){
            vp.push_back({edges[i][2],{edges[i][0],edges[i][1]}});
        }
        sort(vp.begin(),vp.end());
        int res = 0;
        DisjointSet obj(V);
        for(int i=0;i<edges.size();i=i+1){
            int ulpar_u = obj.findParent(vp[i].second.first);
            int ulpar_v = obj.findParent(vp[i].second.second);
            if(ulpar_v != ulpar_u){
                res = res + vp[i].first;
            }
            obj.unionBySize(vp[i].second.first,vp[i].second.second);
        }
        return res;
    }
};