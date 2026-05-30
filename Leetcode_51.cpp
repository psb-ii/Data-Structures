class Solution {
private:
    bool isPossible(vector<string>&v,int curr_col,int curr_row,vector<int>&row,vector<int>&col,vector<int>&upper_dig,vector<int>&lower_dig){
        if(row[curr_row] == 0 && col[curr_col] == 0 && upper_dig[curr_row + curr_col] == 0 && lower_dig[v.size() - 1 + curr_col - curr_row] == 0)
            return true;
        return false; 
    }
    void createAllThePossibleNQueens(int ind,vector<string>&v,vector<vector<string>>&vs,vector<int>&row,vector<int>&col,vector<int>&upper_dig,vector<int>&lower_dig){
        if(ind == v.size()){
            vs.push_back(v);
            return;
        }
        for(int i=0;i<v.size();i=i+1){
            if(isPossible(v,i,ind,row,col,upper_dig,lower_dig)){
                v[ind][i] = 'Q';
                row[ind] = 1;
                col[i] = 1;
                upper_dig[ind+i] = 1;
                lower_dig[v.size() - 1 + i - ind] = 1;
                createAllThePossibleNQueens(ind+1,v,vs,row,col,upper_dig,lower_dig);
                v[ind][i] = '.';
                row[ind] = 0;
                col[i] = 0;
                upper_dig[ind + i] = 0;
                lower_dig[v.size() - 1 + i - ind] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int>row(n,0);
        vector<int>col(n,0);
        vector<int>upper_dig(2*n-1,0);
        vector<int>lower_dig(2*n-1,0);
        vector<vector<string>>vs;
        vector<string>s;
        string blank(n,'.');
        for(int i=0;i<n;i=i+1){
            s.push_back(blank);
        }
        int ind = 0;
        createAllThePossibleNQueens(ind,s,vs,row,col,upper_dig,lower_dig);
        return vs;
    }
};