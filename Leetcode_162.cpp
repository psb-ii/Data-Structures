class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        if(nums.size() == 1)
            return 0;
        if(nums.size() > 1 && nums[low] > nums[low + 1])
            return 0;
        if(nums.size() > 1 && nums[high] > nums[high - 1])
            return high;
        low = 1;
        high = nums.size() - 2;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            if(nums[mid] <= nums[mid+1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};