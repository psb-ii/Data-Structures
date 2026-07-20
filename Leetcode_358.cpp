class Solution {
using v_2d = vector<vector<int>>;
public:
    int maxCoins(vector<int>& nums) {
        int start = 1;
        int end = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        v_2d dp(nums.size()+2,vector<int>(nums.size()+2,-1));
        for(int i=0;i<nums.size();i=i+1){
            for(int j=0;j<nums.size();j=j+1){
                if(i > j)
                    dp[i][j] = 0;
            }
        }
        for(int i=nums.size()-2;i>=1;i=i-1){
            for(int j=i;j<nums.size()-1;j=j+1){
                int maxi = INT_MIN;
                for(int k=i;k<=j;k=k+1){
                    int cost = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi,cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[start][end];
    }
};