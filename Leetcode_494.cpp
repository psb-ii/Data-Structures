class Solution {
using v_2d = vector<vector<int>>;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ind = nums.size() - 1;
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        vector<int>prev(2*total_sum+1,-1);
        int cur_sum = 0;
        for(int i=-1*total_sum;i<=total_sum;i=i+1){
            int count = 0;
            if(i - nums[0] == target)
                count++;
            if(i + nums[0] == target)
                count++;
            prev[i + total_sum] = count;
        }
        vector<int>curr = prev;
        for(int i=1;i<nums.size();i=i+1){
            for(int j=-1*total_sum;j<=total_sum;j=j+1){
                int pos = 0;
                int neg = 0;
                if(j + nums[i] <= total_sum)
                    pos = prev[j+nums[i]+total_sum];
                if(j - nums[i] + total_sum >= 0)
                    neg = prev[j-nums[i]+total_sum];
                curr[j+total_sum] = pos + neg;
            }
            prev = curr;
        }
        return prev[total_sum];
    }
};