class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            if(low + 1 < nums.size() && nums[low] == nums[low + 1])
                low++;
            if(high - 1 >=0 && nums[high] == nums[high - 1])
                high--;
            else{
                int mid = low + ((high - low ) >> 1);
                if(nums[mid] == target)
                    return 1;
                else
                if(nums[low] <= nums[mid]){
                    if(nums[low] <= target && nums[mid] > target)
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                else{
                    if(nums[mid] < target && nums[high] >= target)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
        } 
        if((low <nums.size() && nums[low]==target) || (high >=0 && nums[high]==target))
            return 1;
        return 0;
    }
};