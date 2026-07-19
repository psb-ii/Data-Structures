class Solution {
  using v_2d = vector<vector<int>>;
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int start = 1;
        int end = arr.size()-1;
        v_2d dp(arr.size(),vector<int>(arr.size(),-1));
        for(int i=0;i<arr.size();i=i+1){
            dp[i][i] = 0;
        }
        for(int i=arr.size()-1;i>=1;i=i-1){
            for(int j=i+1;j<arr.size();j=j+1){
                int mini = 1e9;
                for(int k=i;k<j;k=k+1){
                    int operations = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini,operations);
                }
                dp[i][j] = mini;
            }
        }
        return dp[start][end];
    }
};