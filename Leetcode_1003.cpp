class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int left = 0;
        int right = 0;
        int remaining_inversions = k;
        while(right < nums.size()){
            remaining_inversions += nums[right] == 1 ? 0 : -1;
            while(remaining_inversions < 0){
                remaining_inversions += nums[left] == 0 ? 1 : 0;
                left++;
            }
            res = max(res,right-left+1);
            right++;
        }
        return res;
    }
};