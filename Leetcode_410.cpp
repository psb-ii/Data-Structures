class Solution {
private:
    bool isPossible(vector<int>&nums,int max_sum,int max_subarrays_possible){
        int curr_sum = 0;
        int curr_subarrays = 0;
        for(int i=0;i<nums.size();i=i+1){
            curr_sum +=nums[i];
            if(curr_sum > max_sum){
                curr_sum = nums[i];
                curr_subarrays++;
            }
        }
        curr_subarrays++;
        return curr_subarrays <= max_subarrays_possible;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        Solution sol;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0); // high can sure be one of the answers
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(sol.isPossible(nums,mid,k))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};