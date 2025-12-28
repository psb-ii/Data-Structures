class Solution {
private: 
    int findMaximumIndexInTheColumn(vector<vector<int>>&matrix,int col){
        int maxi = INT_MIN;
        int ind = 0;
        for(int i=0;i<matrix.size();i=i+1){
            if(maxi < matrix[i][col]){
                maxi = max(maxi,matrix[i][col]);
                ind = i;
            }
        }
        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int>location;
        int low = 0;
        int high = mat[0].size() - 1;
        while(low <= high){
            int mid = low + ((high - low) >> 1); // column number
            int max_ind = findMaximumIndexInTheColumn(mat,mid);  // row number
            int element = mat[max_ind][mid];
            int left = -1, right = -1;
            if(mid - 1 >= 0)
                left = mat[max_ind][mid-1];
            if(mid + 1 < mat[0].size())
                right = mat[max_ind][mid+1];
            if(element > left && element > right){  // only check right and left because this element is maximum in the column
                location.insert(location.end(),{max_ind,mid});
                return location;
            }
            else
            if(element < left)
                high = mid-1;
            else
                low = mid+1;
        }
        return location;
    }
};