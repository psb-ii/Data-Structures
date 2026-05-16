class Solution {
private:
    bool isBoundary(int x,int y,vector<vector<int>>&grid){
        if(x == 0 || x == grid.size()-1 || y == 0 || y == grid[x].size()-1)
            return true;
        return false;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>qu;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int total_land = 0;
        for(int i=0;i<grid.size();i=i+1){
            for(int j=0;j<grid[i].size();j=j+1){
                if(grid[i][j]){
                    total_land++;
                    if(isBoundary(i,j,grid)){
                        total_land--;
                        vis[i][j] = 1;
                        qu.push({i,j});
                    }
                }
            }
        }
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        while(qu.size()){
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop();
            for(int i=0;i<4;i=i+1){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[x].size() && !vis[new_x][new_y] && grid[new_x][new_y]){
                    qu.push({new_x,new_y});
                    vis[new_x][new_y] = 1;
                    total_land--;
                }
            }
        }
        return total_land;
    }
};