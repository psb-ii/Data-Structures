class Solution {
using twod_vector = vector<vector<int>>;
using oned_vector = vector<int>;
private:
    void generateAllPossibleSubsets(int ind,oned_vector &nums,oned_vector &curr,twod_vector &v){
        if(ind == nums.size()){
            v.push_back(curr);
            return;
        }
        generateAllPossibleSubsets(ind+1,nums,curr,v);
        curr.push_back(nums[ind]);
        generateAllPossibleSubsets(ind+1,nums,curr,v);
        curr.pop_back();  // do not forget to remove this recently added element
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        oned_vector curr;
        twod_vector v;
        int ind = 0;
        generateAllPossibleSubsets(ind,nums,curr,v);
        return v;
    }
};