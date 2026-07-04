class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        int sum = 0;
        if(total_sum & 1)
            return false;
        else
            sum = total_sum >> 1;
        vector<bool>prev(sum+1,false);
        prev[0]=true;
        vector<bool>curr(sum+1,false);
        curr[0]=true;
        for(int i=1;i<nums.size();i=i+1){
            for(int j=1;j<=sum;j=j+1){
                bool not_taken = prev[j];
                int taken = false;
                if(j >= nums[i])
                    taken = prev[j-nums[i]];
                curr[j] = taken | not_taken;
            }
            prev = curr;
        }
        return prev[sum];
    }
};