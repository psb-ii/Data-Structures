class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int curr_max = nums[0];
        int steps = 1;
        int pos = 0;
        while(curr_max + 1 < nums.size()){
            int j=pos;
            int valid_pos = curr_max;
            steps++;
            while(j<nums.size() && j<=valid_pos){
                curr_max = max(curr_max,j+nums[j]);
                j++;
            }
            if(curr_max + 1 >= nums.size())
                break;
            pos = valid_pos;
        }
        return steps;
    }
};