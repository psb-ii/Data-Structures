class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int curr_sum = 0;
        for(int i=0;i<nums.size();i=i+1){
            curr_sum = curr_sum + nums[i];
            maxi = max(maxi,curr_sum);
            if(curr_sum < 0)
                curr_sum = 0;
        }
        return maxi;
    }
};