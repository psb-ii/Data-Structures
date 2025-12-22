class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix_prod = 1;
        int suffix_prod = 1;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i=i+1){
            prefix_prod *=nums[i];
            suffix_prod *=nums[nums.size() -i -1];
            maxi = max({prefix_prod,suffix_prod,maxi});
            if(nums[i] == 0)
                prefix_prod = 1;
            if(nums[nums.size() - i -1] == 0)
                suffix_prod = 1;
        }
        return maxi;
    }
};