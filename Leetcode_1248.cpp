class Solution {
private:
    int countSubarrays(vector<int>&nums,int k){
        int left = 0;
        int right = 0;
        unsigned int total_subarrays = 0;
        int curr_odd = 0;
        while(right < nums.size()){
            curr_odd += nums[right] & 1 ? 1 : 0;
            while(curr_odd > k && left <= right)
                curr_odd -= nums[left++] & 1 ? 1 : 0;
            total_subarrays +=  right - left + 1;
            right +=1;
        }
        return total_subarrays;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubarrays(nums,k) - countSubarrays(nums,k-1);
    }
};