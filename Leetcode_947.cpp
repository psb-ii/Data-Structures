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
    int removeStones(vector<vector<int>>& stones) {
        int numRows=0;
        int numCols=0;
        unordered_map<int,int>maRows;
        unordered_map<int,int>maCols;
        for(int i=0;i<stones.size();i=i+1){
            numRows = max(numRows,stones[i][0]);
            numCols = max(numCols,stones[i][1]);
        }
        DisjointSet obj(numRows+numCols+2);
        for(int i=0;i<stones.size();i=i+1){  
            obj.unionByRank(stones[i][0],stones[i][1]+numRows+1);
            maRows[stones[i][0]]=1;
            maCols[stones[i][1]+numRows+1]=1;
        }
        unordered_set<int>se;
        for(int i=0;i<numRows+numCols+2;i=i+1){
            int ulpar_u = obj.findParent(i);
            if(ulpar_u == i && (maRows.find(i) != maRows.end() || maCols.find(i) != maCols.end()))
                se.insert(ulpar_u);
        }
        int res = stones.size() - se.size();
        return res;
    }
};