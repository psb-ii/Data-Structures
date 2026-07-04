class Solution {
  using v_2d = vector<vector<int>>;
  using v_3d = vector<vector<vector<int>>>;
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        vector<vector<int>>prev(grid[0].size(),vector<int>(grid[0].size(),-1));
        int x1 = 0;
        int x2 = grid[0].size() - 1;
        int y = 0;
        for(int i=0;i<grid[0].size();i=i+1){
            for(int j=0;j<grid[0].size();j=j+1){
                if(i == j)
                    prev[i][j] = grid[grid.size()-1][i];
                else
                    prev[i][j] = grid[grid.size()-1][i] + grid[grid.size()-1][j];
            }
        }
        for(int i=grid.size()-2;i>=0;i=i-1){
            vector<vector<int>>temp(grid[0].size(),vector<int>(grid[0].size(),-1));
            for(int j=0;j<grid[i].size();j=j+1){
                for(int k=0;k<grid[i].size();k=k+1){
                    int maxi = INT_MIN;
                    for(int k1=-1;k1<2;k1=k1+1){
                        for(int k2=-1;k2<2;k2=k2+1){
                            int new_x1 = j + k1;
                            int new_x2 = k + k2;
                            int curr = 0;
                            if(j == k)
                                curr = grid[i][j];
                            else
                                curr = grid[i][j] + grid[i][k];
                            if(new_x1 >= 0 && new_x1 < grid[0].size() && new_x2 >= 0 && new_x2 < grid[0].size()){
                                int new_curr = curr + prev[new_x1][new_x2];
                                maxi = max(maxi,new_curr);
                            }
                        }
                    }
                    temp[j][k] = maxi;
                }
            }
            prev = temp;
        }
        return prev[x1][x2];
    }
};