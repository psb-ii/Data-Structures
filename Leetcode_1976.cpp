class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        const int MOD = 1e9 + 7;
        for(int i=0;i<roads.size();i=i+1){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long int>dist(n,LLONG_MAX);
        vector<long long int>ways(n,0);
        ways[0]=1;
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>minh;
        minh.push({0,0});
        while(minh.size()){
            int node = minh.top().second;
            long long int curr_distance = minh.top().first;
            for(auto it: adj[node]){
                if(dist[it.first] > 1ll*curr_distance + 1ll*it.second){
                    ways[it.first] = 1ll*ways[node] % MOD;
                    dist[it.first] = 1ll*curr_distance + 1ll*it.second;
                    minh.push({1ll*curr_distance+1ll*it.second,it.first});
                }
                else
                if(dist[it.first] == curr_distance + it.second){
                    ways[it.first] = (1ll*ways[it.first] + 1ll*ways[node]) % MOD;
                }
            }
            minh.pop();
        }
        return ways[ways.size()-1];
    }
};