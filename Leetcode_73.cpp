class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col_0 = 1;
        for(int i=0;i<matrix.size();i=i+1){
            for(int j=0;j<matrix[i].size();j=j+1){
                if(matrix[i][j] == 0){
                    if(j == 0)    // ********** very important to note here ***************//
                        col_0 = 0;
                    else{
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for(int i=1;i<matrix.size();i=i+1){
            for(int j=1;j<matrix[i].size();j=j+1){
                if(matrix[i][j]){
                    if(!matrix[0][j]  || !matrix[i][0])
                        matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int i=0;i<matrix[0].size();i=i+1)
                matrix[0][i] = 0;
        }
        if(!col_0){
            for(int i=0;i<matrix.size();i=i+1)
                matrix[i][0] = 0;
        }
    }
};