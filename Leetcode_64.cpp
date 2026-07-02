class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x = grid[0].size() - 1;
        int y = grid.size() - 1;
        vector<int>prev(grid[0].size(),0);
        for(int i=0;i<grid.size();i=i+1){
            vector<int>curr(grid[0].size(),0);
            for(int j=0;j<grid[i].size();j=j+1){
                if(i == 0 && j == 0)
                    curr[0] = grid[0][0];
                else{
                    int left = INT_MAX;
                    int up = INT_MAX;
                    if(i - 1 >= 0)
                        up = grid[i][j] + prev[j];
                    if(j - 1 >= 0)
                        left = grid[i][j] + curr[j-1];
                    curr[j] = min(up,left);
                }
            }
            prev = curr;
        }
        return prev[x];
    }
};