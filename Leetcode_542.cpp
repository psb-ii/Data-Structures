class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>>qu;
        vector<vector<int>>res = mat;
        vector<vector<bool>>vis(mat.size(),vector<bool>(mat[0].size(),false));
        for(int i=0;i<mat.size();i=i+1){
            for(int j=0;j<mat[0].size();j=j+1){
                if(mat[i][j] == 0){
                    qu.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        while(qu.size()){
            int x = qu.front().first.first;
            int y = qu.front().first.second;
            int dist = qu.front().second;
            qu.pop();
            for(int i=0;i<4;i=i+1){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 && new_x < mat.size() && new_y >= 0 && new_y <mat[0].size() && !vis[new_x][new_y] && mat[new_x][new_y]){
                    vis[new_x][new_y] = true;
                    res[new_x][new_y] = dist + 1;
                    qu.push({{new_x,new_y},dist+1});
                }
            }
        }
        return res;
    }
};