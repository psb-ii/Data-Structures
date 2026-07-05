class Solution {
  using v_2d = vector<vector<int>>;
  private:
    int countOfPerfectSum(int ind,int target,vector<int>&arr,v_2d &dp){
        if(ind == 0){
            if(target == 0 && arr[0] == 0)
                return 2;
            else
            if(target - arr[0] == 0)
                return 1;
            else
            if(target == 0)
                return 1;
            else
                return 0;
        }
        if(dp[ind][target] != -1)
            return dp[ind][target];
        int taken = 0;
        int not_taken = countOfPerfectSum(ind-1,target,arr,dp);
        if(target >= arr[ind])
            taken = countOfPerfectSum(ind-1,target-arr[ind],arr,dp);
        return dp[ind][target] = taken + not_taken; 
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        v_2d dp(arr.size(),vector<ixnt>(target+1,-1));
        int ind = arr.size() - 1;
        return countOfPerfectSum(ind,target,arr,dp);
    }
};