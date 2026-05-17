class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i=i+1){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>>qu;
        vector<int>dis(n,INT_MAX);
        dis[src] = 0;
        qu.push({0,{src,0}});
        while(qu.size()){
            int stops = qu.front().first;
            int node = qu.front().second.first;
            int current_dis = qu.front().second.second;
            qu.pop();
            cout <<stops<<" "<<node<<" "<<current_dis<<endl;
            if(stops > k)
                continue;
            for(auto n: adj[node]){
                if((current_dis + n.second) < dis[n.first] && stops <= k){
                    qu.push({stops+1,{n.first,current_dis+n.second}});
                    dis[n.first]=current_dis+n.second;
                }
            }
        }
        if(dis[dst] != INT_MAX)
            return dis[dst];
        return -1;
    }
};