class Solution {
private:
    int countSubarrays(vector<int>&nums,int goal){
        int curr_sum = 0;
        int left = 0;
        int right = 0;
        int total_subarrays = 0;
        while(right < nums.size()){
            curr_sum +=nums[right];
            while(curr_sum > goal && left<=right)
                curr_sum -=nums[left++];
            int subarray_len = right - left + 1;
            total_subarrays += subarray_len;
            right++; 
        }
        return total_subarrays;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubarrays(nums,goal) - countSubarrays(nums,goal-1);
    }
};