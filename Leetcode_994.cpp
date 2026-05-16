class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>qu;  // {{x,y},time}
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i=i+1){
            for(int j=0;j<grid[0].size();j=j+1){
                if(grid[i][j] == 2){
                    vis[i][j] = true;
                    qu.push({{i,j},0});
                }
            }
        }
        int time = 0;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        while(qu.size()){
            int x = qu.front().first.first;
            int y = qu.front().first.second;
            int curr_time = qu.front().second;
            time = max(time,curr_time);
            qu.pop();
            for(int i=0;i<4;i=i+1){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x < grid.size() && new_y < grid[x].size() && !vis[new_x][new_y] && grid[new_x][new_y] == 1){
                    vis[new_x][new_y] = true;
                    qu.push({{new_x,new_y},curr_time+1});
                }
            }
        }
        for(int i=0;i<grid.size();i=i+1){
            for(int j=0;j<grid[i].size();j=j+1){
                if(grid[i][j] == 1 && !vis[i][j])
                    time = -1;
            }
        }
        return time;
    }
};