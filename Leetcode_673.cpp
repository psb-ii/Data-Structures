class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        vector<int>count_len(nums.size(),1);
        int maxi = 1;
        for(int i=1;i<nums.size();i=i+1){
            for(int j=0;j<i;j=j+1){
                if(nums[i] > nums[j]){
                    if(dp[i] == dp[j] + 1){
                        count_len[i] +=count_len[j]; 
                    }
                    else
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        count_len[i] = count_len[j];
                    }
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int count = maxi == 1 ? nums.size() : 0;
        for(int i=1;i<nums.size();i=i+1){
            if(dp[i] == maxi && maxi > 1){
                for(int j=0;j<i;j=j+1){
                    if(nums[i] > nums[j] && dp[j] == maxi - 1){
                        count +=count_len[j];
                    }
                }
            }
        }
        return count;
    }
};