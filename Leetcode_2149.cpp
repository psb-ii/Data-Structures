class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos_ind = 0;
        int neg_ind = 0;
        vector<int>rearranged(nums.size());
        for(int i=0;i<nums.size();i=i+2){
            while(nums[pos_ind] < 0)
                pos_ind++;
            rearranged[i] = nums[pos_ind++];
            while(nums[neg_ind] > 0)
                neg_ind++;
            rearranged[i + 1] = nums[neg_ind++];
        }
        return rearranged;
    }
};