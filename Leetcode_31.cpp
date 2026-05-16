class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        for(int i=nums.size()-2;i>=0;i=i-1){
            if(nums[i+1] > nums[i]){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int swap_ind = 0;
            for(int i=nums.size()-1;i>ind;i=i-1){
                if(nums[i] > nums[ind]){
                    swap_ind = i;
                    break;
                }
            }
            swap(nums[swap_ind],nums[ind]);
            reverse(nums.begin()+ind+1,nums.end());
        }
    }
};