class Solution {
private:
    bool doesSubsequenceWithGivenSumExist(int ind,int curr_sum,vector<int>&arr,int k){
        if(ind == arr.size()){
            // cout << curr_sum <<" ";
            return curr_sum == k;
        }
        bool not_taken = doesSubsequenceWithGivenSumExist(ind+1,curr_sum,arr,k);
        bool taken = false;
        if(curr_sum + arr[ind] <= k){
            curr_sum = curr_sum + arr[ind];
            taken = doesSubsequenceWithGivenSumExist(ind+1,curr_sum,arr,k);
            curr_sum = curr_sum - arr[ind];
        }
        return taken | not_taken;
    }
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        int ind = 0;
        int curr_sum = 0;
        return doesSubsequenceWithGivenSumExist(ind,curr_sum,arr,k);
    }
};