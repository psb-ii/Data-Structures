class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size() - 1;
        int col = 0;
        int count_negatives = 0;
        while(row >=0 && col < grid[0].size())
        {
            if(grid[row][col] >= 0)
                col +=1;
            else{
                count_negatives += (grid[0].size() - col);
                row -=1;
            }
        }
        return count_negatives;

    }
};