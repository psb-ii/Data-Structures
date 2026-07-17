class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        vector<int>dp(arr.size(),1);
        vector<int>hash(arr.size());
        vector<int>lis;
        int maxi = 0;
        int last_ind = 0;
        for(int i=0;i<arr.size();i=i+1){
            hash[i]=i;
            for(int j=0;j<i;j=j+1){
                if(arr[j] < arr[i] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                last_ind = i;
            }
        }
        lis.push_back(arr[last_ind]);
        while(last_ind != hash[last_ind]){
            lis.push_back(arr[hash[last_ind]]);
            last_ind = hash[last_ind];
        }
        reverse(lis.begin(),lis.end());
        return lis;
    }
};