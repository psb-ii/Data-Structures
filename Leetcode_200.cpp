class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        int count_islands = 0;
        for(int i=0;i<grid.size();i=i+1){
            for(int j=0;j<grid[i].size();j=j+1){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count_islands +=1;
                    queue<pair<int,int>>qu;
                    vis[i][j] = 1;
                    qu.push({i,j});
                    while(qu.size()){
                        int x = qu.front().first;
                        int y = qu.front().second;
                        qu.pop();
                        for(int k=0;k<4;k=k+1){
                            int new_x = x + dx[k];
                            int new_y = y + dy[k];
                            if(new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[x].size() && !vis[new_x][new_y] && grid[new_x][new_y] == '1'){
                                vis[new_x][new_y] = 1;
                                qu.push({new_x,new_y});
                            }
                        }
                    }
                }
            }
        }
        return count_islands;
    }
};