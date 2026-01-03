class Solution {
using oned_vector = vector<int>;
using twod_vector = vector<vector<int>>;
private:
    void getAllPossibleSubsets(int ind,oned_vector &temp,oned_vector &nums,twod_vector &res){
        res.push_back(temp);
        for(int i=ind;i<nums.size();i=i+1){
            if(i>ind && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);
            getAllPossibleSubsets(i+1,temp,nums,res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ind = 0;
        oned_vector temp;
        twod_vector res;
        getAllPossibleSubsets(ind,temp,nums,res);
        return res;
    }
};