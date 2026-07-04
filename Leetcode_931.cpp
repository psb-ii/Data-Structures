class Solution {
using v_2d = vector<vector<int>>;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        int y = matrix.size() - 1;
        v_2d dp(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
        for(int i=0;i<matrix[0].size();i=i+1){
            dp[0][i] = matrix[0][i];
        }
        for(int i=1;i<matrix.size();i=i+1){
            for(int j=0;j<matrix[i].size();j=j+1){
                int mini = INT_MAX;
                for(int k=-1;k<2;k=k+1){
                    if(k+j < matrix[i].size() && k+j >= 0){
                        int curr = matrix[i][j] + dp[i-1][k+j];
                        mini = min(curr,mini);
                    }
                }
                dp[i][j] = mini;
            }
        }
        for(int i=0;i<matrix[0].size();i=i+1){
            res = min(res,dp[y][i]);
        }
        return res;
    }
};