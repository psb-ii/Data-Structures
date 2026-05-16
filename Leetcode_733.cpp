class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>>vis(image.size(),vector<bool>(image[0].size(),false));
        vector<vector<int>>filled = image;
        queue<pair<int,int>>qu;
        int original_color = image[sr][sc];
        qu.push({sr,sc});
        vis[sr][sc] = true;
        filled[sr][sc] = color;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        while(qu.size()){
            int row = qu.front().first;
            int col = qu.front().second;
            qu.pop();
            for(int i=0;i<4;i=i+1){
                int new_row = row + dx[i];
                int new_col = col + dy[i];
                if(new_row < image.size() && new_col < image[row].size() && !vis[new_row][new_col] && image[new_row][new_col] == original_color){
                    vis[new_row][new_col] = true;
                    filled[new_row][new_col] = color;
                    qu.push({new_row,new_col});
                }
            }
        }
        return filled;
    }
};