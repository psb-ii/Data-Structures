class Solution {
private:
    int maxRobberyPossibleTonight(int start, int end, vector<int>&nums){
        if(start < 0)
            return 0;
        int prev2 = nums[start];
        int prev1 = prev2; 
        for(int ind=nums.size()-2;ind>=end;ind=ind-1){
            int taken = nums[ind];
            if(ind + 2 < start + 1)
                taken = nums[ind] + prev2;
            int not_taken = prev1;
            int curr = max(taken,not_taken);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        return max(maxRobberyPossibleTonight(nums.size()-1,1,nums),maxRobberyPossibleTonight(nums.size()-2,0,nums));
    }
};