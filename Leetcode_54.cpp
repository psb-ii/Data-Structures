class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        vector<int>res;
        int count = 0; 
        int total = matrix.size() * matrix[0].size();
        while(left <= right && top <= bottom){
            for(int i=left;i<=right && count < total;i=i+1){ // important to check count < total
                res.emplace_back(matrix[top][i]);
                count +=1;
            }
            top +=1;
            for(int i=top;i<=bottom && count < total;i=i+1){
                res.push_back(matrix[i][right]);
                count +=1;
            }
            right -=1;
            for(int i=right;i>=left && count < total;i=i-1){
                res.emplace_back(matrix[bottom][i]);
                count +=1;
            }
            bottom -=1;
            for(int i=bottom;i>=top && count < total;i=i-1){
                res.push_back(matrix[i][left]);
                count +=1;
            }
            left +=1;
        }
        return res;
    }
};