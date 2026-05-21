class DisjointSet{
vector<int>rank;
vector<int>parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i=i+1){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulpar_u = findParent(u);
        int ulpar_v = findParent(v);
        if(ulpar_u == ulpar_v)
            return ;
        if(rank[ulpar_u] < rank[ulpar_v]){
            parent[ulpar_u] = ulpar_v;
        }
        else
        if(rank[ulpar_v] < rank[ulpar_u]){
            parent[ulpar_v] = ulpar_u;
        }
        else{
            parent[ulpar_u] = ulpar_v;
            rank[ulpar_v] = rank[ulpar_v] + 1;
        }
    }
    void unionBySize(int u,int v){
        int ulpar_u = findParent(u);
        int ulpar_v = findParent(v);
        if(ulpar_u == ulpar_v)
            return ;
        if(rank[ulpar_u] < rank[ulpar_v]){
            parent[ulpar_u] = ulpar_v;
            rank[ulpar_v] = rank[ulpar_v] + rank[ulpar_u];
        }
        else{
            parent[ulpar_v] = ulpar_v;
            rank[ulpar_u] = rank[ulpar_u] + rank[ulpar_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>ma;
        unordered_map<int,string>mare;
        unordered_map<string,string>mapper;
        vector<vector<string>>vs;
        int curr = 0;
        for(int i=0;i<accounts.size();i=i+1){
            for(int j=1;j<accounts[i].size();j=j+1){
                if(ma.find(accounts[i][j]) == ma.end()){
                    ma[accounts[i][j]] = curr;
                    mare[curr]=accounts[i][j];
                    curr = curr + 1;
                }
                mapper[accounts[i][j]] = accounts[i][0];
            }
        }
        vector<string>connect[curr];
        DisjointSet obj(curr);
        for(int i=0;i<accounts.size();i=i+1){
            int u = ma[accounts[i][1]];
            for(int j=2;j<accounts[i].size();j=j+1){
                int v = ma[accounts[i][j]];
                obj.unionByRank(u,v);
            }
        }
        for(int i=0;i<curr;i=i+1){
            int ulpar_u = obj.findParent(i);
            connect[ulpar_u].push_back(mare[i]);
        }
        for(int i=0;i<curr;i=i+1){
            sort(connect[i].begin(),connect[i].end());
            if(connect[i].size()){
                string name = mapper[mare[i]];
                vector<string>v;
                v.push_back(name);
                for(int j=0;j<connect[i].size();j=j+1){
                    v.push_back(connect[i][j]);
                }
                vs.push_back(v);
            }
        }
        return vs;
    }
};