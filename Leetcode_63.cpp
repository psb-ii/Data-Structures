class Solution {
using v_2d = vector<vector<int>>;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int>temp(m,0);
        temp[0]=1;
        const int MOD = 2*1e9;
        if(obstacleGrid[0][0] || obstacleGrid[n-1][m-1])
            return 0;
        for(int i=0;i<n;i=i+1){
            vector<int>curr(m,0);
            curr[0]=1;
            for(int j=0;j<m;j=j+1){
                long long int left = 0;
                long long int up = 0;
                if(i | j){
                    if(i-1 >= 0 && obstacleGrid[i-1][j] != 1)
                        up = temp[j];
                    if(j-1 >= 0 && obstacleGrid[i][j-1] != 1)
                        left = curr[j-1];
                    curr[j] = (1ll*up + 1ll*left) % MOD;
                }
            }
            temp = curr;
        }
        return temp[m-1];
    }
};