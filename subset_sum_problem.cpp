class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<bool>prev(sum+1,false);
        prev[0] = true;
        vector<bool> curr(sum+1,false);
        curr[0] = true;
        int ind = arr.size() - 1;
        // for(int i=0;i<arr.size();i=i+1)
        //     dp[i][0] = true;
        if(arr[0] <= sum)
            prev[arr[0]] = true;
        for(int i=1;i<arr.size();i=i+1){
            for(int j=1;j<=sum;j=j+1){
                bool taken = 0;
                bool not_taken = prev[j];
                if(j >= arr[i])
                    taken = prev[j-arr[i]];
                curr[j] = taken | not_taken;
            }
            prev = curr;
        }
        return prev[sum];
    }
};