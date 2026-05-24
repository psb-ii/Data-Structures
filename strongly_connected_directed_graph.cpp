#include<iostream>
#include<vector>
using namespace std;
void performTopologicalSortingInADirectedGraph(int node,vector<int>&visited,stack<int>&topological_order,vector<int>*adj){
    visited[node]=1;
    for(auto it: adj[node]){
        if(!visited[it])
            performTopologicalSortingInADirectedGraph(it,visited,topological_order,adj);
    }
    topological_order.push(node);
}
void performDfsTraversalInADirectedGraph(int node,vector<int>&visited,vector<int>*opp_dir,vector<int>&component){
    visited[node]=1;
    component.push_back(node);
    for(auto it: opp_dir[node]){
        if(!visited[it]){
            performDfsTraversalInADirectedGraph(it,visited,opp_dir,component);
        }
    }
}
void findAllStronglyConnectedComponentsInADirectedGraph(int n,vector<pair<int,int>>&vp){
    int nodes = n;
    vector<int>adj[nodes];
    for(int i=0;i<vp.size();i=i+1){
        adj[vp[i].first].push_back(vp[i].second);
    }
    vector<int>visited(nodes,0);
    stack<int>topological_order;
    for(int i=0;i<nodes;i=i+1){
        if(!visited[i]){
            performTopologicalSortingInADirectedGraph(i,visited,topological_order,adj);
        }
    }
    vector<int>opp_dir[nodes];
    for(int i=0;i<vp.size();i=i+1){
        opp_dir[vp[i].second].push_back(vp[i].first);
    }
    for(int i=0;i<nodes;i=i+1){
        visited[i]=0;
    }
    vector<vector<int>>strongly_connected_components;
    while(topological_order.size()){
        if(!visited[topological_order.top()]){
            vector<int>component;
            performDfsTraversalInADirectedGraph(topological_order.top(),visited,opp_dir,component);
            strongly_connected_components.push_back(component);
        }
        topological_order.pop();
    }
    for(int i=0;i<strongly_connected_components.size();i=i+1){
        for(int j=0;j<strongly_connected_components[i].size();j=j+1){
            cout <<strongly_connected_components[i][j];
        }
        cout <<endl;
    }
}
int main(){
    int n;
    int edges;
    cin >>n;
    cin >>edges;
    vector<pair<int,int>>vp;
    for(int i=0;i<edges;i=i+1){
        int node1,node2;
        cin >>node1;
        cin >>node2;
        vp.push_back({node1,node2});
    }
    findAllStronglyConnectedComponentsInADirectedGraph(n,vp);
}