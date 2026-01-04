class Solution {
using twod_i = vector<vector<int>>;
using twod_c = vector<vector<char>>;
private:
    bool wordExistsOrNot(int ind,int row,int col,twod_i &visited,string &word,twod_c &board){
        if(ind == word.size())
            return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;
        if(visited[row][col])
            return false;
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};
        bool res = false;
        for(int i=0;i<4;i=i+1){
            int new_r = row + dr[i];
            int new_c = col + dc[i];
            if(row < 0 || row > board.size() || col <0 || col > board[0].size())
                continue;
            if(word[ind] == board[row][col]){
                visited[row][col] = 1;
                res |= wordExistsOrNot(ind+1,new_r,new_c,visited,word,board);
                visited[row][col] = 0;
            }
        }
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ind = 0;
        twod_i visited(board.size(),vector<int>(board[0].size(),0));
        for(int row=0;row<board.size();row=row+1){
            for(int col=0;col<board[0].size();col=col+1){
                if(wordExistsOrNot(ind,row,col,visited,word,board))
                    return true;
            }
        }
        return false;
        
    }
};