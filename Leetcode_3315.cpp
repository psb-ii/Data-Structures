class Solution {
private:
    int getLeftMostEligibleBit(int num){
        int bit = 30;
        while(bit >= 0){
            if(num >= (1<<bit)){
                int new_num = (num - (1<<bit)) | (num - (1<<bit) + 1);
                if(new_num == num)
                    return bit;
            }
            bit--;
        }
        return bit;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i=i+1){
            int bit = getLeftMostEligibleBit(nums[i]);
            if(bit == -1)
                res.push_back(-1);
            else
                res.push_back(nums[i] - (1<<bit));
        }
        return res;
    }
};