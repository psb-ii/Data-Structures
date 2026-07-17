class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),1);
        vector<int>hash(nums.size());
        vector<int>res;
        int maxi = 0;
        int lastind = 0;
        for(int i=0;i<nums.size();i=i+1){
            hash[i]=i;
            for(int j=0;j<i;j=j+1){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                lastind = i;
            }
        }
        res.push_back(nums[lastind]);
        while(lastind != hash[lastind]){
            res.push_back(nums[hash[lastind]]);
            lastind = hash[lastind];
        }
        return res;
    }
};