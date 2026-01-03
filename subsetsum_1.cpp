class Solution {
  private:
  void getAllPossibleSum(int ind,int curr_sum,vector<int>&subsetsum,vector<int>&nums){
    if(ind == nums.size()){
      subsetsum.push_back(curr_sum);
      return;
    }
    getAllPossibleSum(ind+1,curr_sum,subsetsum,nums);
    getAllPossibleSum(ind+1,curr_sum+nums[ind],subsetsum,nums);
  }
  public:
    vector<int> subsetSums(vector<int>& nums) {
        //your code goes here
        int ind = 0;
        int curr_sum = 0;
        vector<int>subsetsum;
        getAllPossibleSum(ind,curr_sum,subsetsum,nums);
        return subsetsum;
    }
};