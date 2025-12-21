class Solution {
private:
    bool checkIfExistsRequiredTimesOrNot(int element,vector<int>&nums){
        int freq = 0;
        for(int i=0;i<nums.size();i=i+1){
            freq +=nums[i] == element ? 1 : 0;
        }
        return freq > (nums.size()/3);
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        int element1, ct1 = 0, element2, ct2 = 0;
        for(int i=0;i<nums.size();i=i+1){
            if(ct1 == 0 && nums[i] != element2){
                ct1++;
                element1=nums[i];
            }
            else
            if(ct2 == 0 && nums[i] != element1){
                ct2++;
                element2=nums[i];
            }
            else
            if(nums[i] == element1)
                ct1++;
            else
            if(nums[i] == element2)
                ct2++;
            else{
                ct1--;
                ct2--;
            }
        }
        vector<int>res;
        bool c1 = checkIfExistsRequiredTimesOrNot(element1,nums);
        if(c1)
            res.emplace_back(element1);
        bool c2 = checkIfExistsRequiredTimesOrNot(element2,nums);
        if(c2)
            res.push_back(element2);
        return res;
    }
};