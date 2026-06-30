class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = nums[nums.size()-1];
        int prev1 = prev2; 
        for(int ind=nums.size()-2;ind>=0;ind=ind-1){
            int taken = nums[ind];
            if(ind + 2 < nums.size())
                taken = nums[ind] + prev2;
            int not_taken = prev1;
            int curr = max(taken,not_taken);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};