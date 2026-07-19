class Solution {
using v_2d = vector<vector<int>>;
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int start = 0;
        int end = cuts.size() - 1;
        sort(cuts.begin(),cuts.end());
        v_2d dp(cuts.size(),vector<int>(cuts.size(),-1));
        for(int i=1;i<cuts.size();i=i+1){
            dp[i-1][i] = 0;
        }
        for(int i=cuts.size()-2;i>=0;i=i-1){
            for(int j=i+2;j<cuts.size();j=j+1){
                int mini = 1e9;
                for(int k=i+1;k<j;k=k+1){
                    int curr_cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                    mini = min(mini,curr_cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[start][end];
    }
};