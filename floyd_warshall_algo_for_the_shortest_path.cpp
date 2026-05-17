// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dis) {
        // Code here
        for(int i=0;i<dis.size();i=i+1){
            for(int j=0;j<dis.size();j=j+1){
                for(int k=0;k<dis.size();k=k+1){
                    if(dis[j][i] != 1e8 && dis[i][k] != 1e8) 
                        dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
                }
            }
        }
    }
};