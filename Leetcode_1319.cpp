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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() <= n-2)
            return -1;
        DisjointSet obj(n);
        for(int i=0;i<connections.size();i=i+1){
            obj.unionByRank(connections[i][0],connections[i][1]);
        }
        unordered_set<int>se;
        for(int i=0;i<n;i=i+1){
            int ulpar_u = obj.findParent(i);
            se.insert(ulpar_u);
        }
        int detachments = se.size() - 1;
        return detachments;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() <= n-2)
            return -1;
        DisjointSet obj(n);
        for(int i=0;i<connections.size();i=i+1){
            obj.unionByRank(connections[i][0],connections[i][1]);
        }
        unordered_set<int>se;
        for(int i=0;i<n;i=i+1){
            int ulpar_u = obj.findParent(i);
            se.insert(ulpar_u);
        }
        int detachments = se.size() - 1;
        return detachments;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() <= n-2)
            return -1;
        DisjointSet obj(n);
        for(int i=0;i<connections.size();i=i+1){
            obj.unionByRank(connections[i][0],connections[i][1]);
        }
        unordered_set<int>se;
        for(int i=0;i<n;i=i+1){
            int ulpar_u = obj.findParent(i);
            se.insert(ulpar_u);
        }
        int detachments = se.size() - 1;
        return detachments;
    }
};