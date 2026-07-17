class Solution {
using v_2d = vector<vector<int>>;
public:
    int lengthOfLIS(vector<int>& nums) {
        int curr_ind = 0;
        int prev_ind = -1;
        v_2d dp(nums.size()+1,vector<int>(nums.size()+2,-1));
        for(int i=0;i<=nums.size()+1;i=i+1){
            dp[nums.size()][i]=0;
        }
        for(int i=nums.size()-1;i>=0;i=i-1){
            for(int j=-1;j<nums.size()+1;j=j+1){
                int taken = 0;
                int not_taken = 0;
                if(j == -1 || nums[i] > nums[j])
                    taken = 1 + dp[i+1][i];
                not_taken = dp[i+1][j+1];
                dp[i][j + 1] = max(taken,not_taken);
            }
        }
        return dp[curr_ind][prev_ind+1];
    }
};