class Solution {
  private:
    void increasingSubsequenceFromLeft(vector<int>&nums,vector<int>&dp1){
        for(int i=1;i<nums.size();i=i+1){
            for(int j=0;j<i;j=j+1){
                if(nums[i] > nums[j]){
                    dp1[i] = max(dp1[i],dp1[j]+1);
                }
            }
        }
    }
    void increasingSubsequenceFromRight(vector<int>&nums,vector<int>&dp2){
        for(int i=nums.size()-1;i>=0;i=i-1){
            for(int j=i+1;j<nums.size();j=j+1){
                if(nums[i] > nums[j]){
                    dp2[i] = max(dp2[i],dp2[j]+1);
                }
            }
        }
    }
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>dp1(nums.size(),0);
        vector<int>dp2(nums.size(),0);
        increasingSubsequenceFromLeft(nums,dp1);
        increasingSubsequenceFromRight(nums,dp2);
        int maxi = 0;
        for(int i=1;i<nums.size()-1;i=i+1){
            if(dp1[i] && dp2[i]){
                maxi = max(maxi,dp1[i] + dp2[i] + 1);
            }
        }
        return maxi;
    }
};
