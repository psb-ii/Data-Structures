class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        vector<int>dp(heights.size(),-1);
        dp[heights.size()-1] = 0;
        for(int ind=heights.size()-2;ind>=0;ind=ind-1){
            int min_energy = INT_MAX;
            for(int i=1;i<=k;i=i+1){
                if(ind + i < heights.size()){
                    int curr_energy = abs(heights[ind]-heights[ind+i]) + dp[i+ind];
                    min_energy = min(min_energy,curr_energy);
                }
            }
            dp[ind] = min_energy;
        }
        return dp[0];
    }
};
