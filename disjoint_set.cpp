#include<iostream>
#include<vector>
using namespace std;
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
int main(){
    DisjointSet obj(7);
    obj.unionBySize(1,2);
    obj.unionBySize(2,3);
    obj.unionBySize(4,5);
    cout <<obj.findParent(1)<<" "<<obj.findParent(5);
    obj.unionBySize(5,6);
    obj.unionBySize(6,7);
    obj.unionBySize(3,4);
    cout <<obj.findParent(1)<<" "<<obj.findParent(5);
}