class Solution {
private:
    bool isValid(int x,int y,vector<vector<int>>&grid){
        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size())
            return true;
        return false;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),(vector(grid[0].size(),0)));
        queue<pair<pair<int,int>,int>>qu;
        if(!grid[0][0]){
            qu.push({{0,0},1});
            vis[0][0]=1;
        }
        int dx[] = {1,1,1,0,-1,-1,-1,0};
        int dy[] = {1,0,-1,-1,-1,0,1,1};
        while(qu.size()){
            int x = qu.front().first.first;
            int y = qu.front().first.second;
            int steps = qu.front().second;
            qu.pop();
            if(x == grid.size()-1 && y == grid[0].size()-1)
                return steps;
            for(int i=0;i<8;i=i+1){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(isValid(new_x,new_y,grid) && !vis[new_x][new_y] && !grid[new_x][new_y]){
                    vis[new_x][new_y]=1;
                    qu.push({{new_x,new_y},steps+1});
                }
            }
        }
        return -1;
    }
};