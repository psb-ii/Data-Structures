class Solution {
private:
    bool isBoundary(int x,int y,vector<vector<char>>&board){
        if(x == 0 || x == board.size() - 1 || y == 0 || y == board[x].size() - 1)
            return true;
        return false;
    }
    void bfsTraversal(int x,int y,vector<vector<bool>>&vis,vector<vector<char>>&board,int dx[],int dy[]){
        queue<pair<int,int>>qu;
        vis[x][y] = true;
        qu.push({x,y});
        while(qu.size()){
            x = qu.front().first;
            y = qu.front().second;
            qu.pop();
            for(int i=0;i<4;i=i+1){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 & new_x < board.size() && new_y >= 0 && new_y < board[x].size() && !vis[new_x][new_y] && board[new_x][new_y] == 'O'){
                    vis[new_x][new_y] = true;
                    qu.push({new_x,new_y});
                } 
            } 
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),false));
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        for(int i=0;i<board.size();i=i+1){
            for(int j=0;j<board[i].size();j=j+1){
                if(isBoundary(i,j,board) && !vis[i][j] && board[i][j] == 'O'){
                    bfsTraversal(i,j,vis,board,dx,dy);
                }
            }
        }
        for(int i=0;i<board.size();i=i+1){
            for(int j=0;j<board[i].size();j=j+1){
                if(board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};