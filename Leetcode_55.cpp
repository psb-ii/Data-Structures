class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr_max = nums[0];
        for(int i=0;i<nums.size() && curr_max >= i;i=i+1){
            curr_max = max(curr_max,nums[i]+i);
            if(curr_max + 1 >= nums.size())
                return true; 
        }
        return false;
    }
};