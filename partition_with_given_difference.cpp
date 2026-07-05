class Solution {
  private:
    int isPossible(int ind,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(ind == 0){
            if(sum == 0 && arr[ind] == 0)
                return 2;
            else
            if(sum == 0)
                return 1;
            else
            if(sum == arr[ind])
                return 1;
            else
                return 0;
        }
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        int not_taken = isPossible(ind-1,sum,arr,dp);
        int taken = 0;
        if(sum >= arr[ind])
            taken = isPossible(ind-1,sum-arr[ind],arr,dp);
        return dp[ind][sum] = taken + not_taken;
    }
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int sum = accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
        int ind = arr.size() - 1;
        for(int i=0;i<=sum;i=i+1)
            int flag = isPossible(ind,i,arr,dp);
        int total = 0;
        for(int i=0;i<=sum;i=i+1){
            if(dp[ind][i] != 0){
                int rem_sum = sum - i;
                if(dp[ind][rem_sum] != -1 && abs(i-rem_sum) == diff)
                    total = total + min(dp[ind][i],dp[ind][sum-i]);
            }
        }
        if(diff == 0)
            return total;
        return total >> 1;
    }
};