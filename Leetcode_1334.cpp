class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        for(int i=0;i<n;i=i+1)
            dis[i][i] = 0;
        for(int i=0;i<edges.size();i=i+1){
            dis[edges[i][0]][edges[i][1]] = edges[i][2];
            dis[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i=0;i<n;i=i+1){
            for(int j=0;j<n;j=j+1){
                for(int k=0;k<n;k=k+1){
                    if(dis[j][i] != 1e9 && dis[i][k] != 1e9)
                        dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
                }
            }
        }
        int mini = INT_MAX;
        vector<int>r;
        for(int i=0;i<n;i=i+1){
            int curr = 0;
            for(int j=0;j<n;j=j+1){
                if(i!=j && dis[i][j] <= distanceThreshold)
                    curr +=1;
            }
            r.push_back(curr);
            mini = min(mini,curr);
            curr = 0;
        }
        int city = 0;
        for(int i=0;i<r.size();i=i+1){
            if(r[i] == mini)
                city = i;
        }
        return city;
    }
};