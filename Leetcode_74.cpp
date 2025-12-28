class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = (matrix.size() * matrix[0].size()) - 1;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            int row = int(floor(mid/matrix[0].size()));
            int col = mid - (row * matrix[0].size());
            if(matrix[row][col] == target)
                return 1;
            else
            if(matrix[row][col] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return 0;
    }
};