class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int>prev(triangle.size(),INT_MAX);
        for(int i=0;i<triangle.size();i=i+1){
            prev[i] = triangle[triangle.size()-1][i];
        }
        for(int i=triangle.size()-2;i>=0;i=i-1){
            vector<int>curr(triangle.size(),INT_MAX);
            for(int j=0;j<=i;j=j+1){
                int mini = INT_MAX;
                for(int k=0;k<2;k=k+1){
                    if(j+k >= 0){
                        int curr = triangle[i][j] + prev[j+k];
                        mini = min(mini,curr);
                    }
                }
                curr[j] = mini;
            }
            prev = curr;
        }
        return prev[0];
    }
};