class Solution {
using twodc_vector = vector<vector<char>>;
private:
    bool isPossible(char &ch,int row,int col,twodc_vector &board){
        int r_count = 0, c_count = 0, b_count = 0;
        for(int i=0;i<9;i=i+1){
            if(board[row][i] == ch)
                return false;
            if(board[i][col] == ch)
                return false; 
        }
        int r_start = (row / 3) * 3;
        int r_end = r_start + 2;
        int c_start = (col / 3) * 3;
        int c_end = c_start + 2;
        for(int i=r_start;i<=r_end;i=i+1){
            for(int j=c_start;j<=c_end;j=j+1){
                if(board[i][j] == ch)
                    return false;
            }
        }
        return true;
    }
    bool possibleSolution(twodc_vector &board){
        for(int i=0;i<board.size();i=i+1){
            for(int j=0;j<board[i].size();j=j+1){
                if(board[i][j] == '.'){
                    for(int k=1;k<10;k=k+1){
                        char ch = char(k+48);
                        if(isPossible(ch,i,j,board)){
                            board[i][j] = ch;
                            if(possibleSolution(board) == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        possibleSolution(board);
    }
};