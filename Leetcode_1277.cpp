class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>matrices(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i=i+1){
            matrices[i][0] = matrix[i][0];
        }
        for(int i=0;i<matrix[0].size();i=i+1){
            matrices[0][i] = matrix[0][i];
        }
        for(int i=1;i<matrix.size();i=i+1){
            for(int j=1;j<matrix[i].size();j=j+1){
                if(matrix[i][j] == 0)
                    matrices[i][j] = 0;
                else{
                    matrices[i][j] = 1 + min({matrices[i-1][j],matrices[i][j-1],matrices[i-1][j-1]});
                }
            }   
        }
        int res = 0;
        for(int i=0;i<matrices.size();i=i+1){
            for(int j=0;j<matrices[i].size();j=j+1){
                res = res + matrices[i][j];
            }
        }
        return res;
    }
};