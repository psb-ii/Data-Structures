class Solution {
using twod_vector = vector<vector<int>>;
using oned_vector = vector<int>;
private:
    void getAllPossibleCombinations(int ind, int curr_sum, oned_vector &temp, twod_vector &v, oned_vector &candidates, int target){
        if(ind == candidates.size()){
            if(curr_sum == target)
                v.push_back(temp);
            return;
        }
        if(curr_sum + candidates[ind] <= target){
            temp.push_back(candidates[ind]);
            getAllPossibleCombinations(ind,curr_sum + candidates[ind],temp,v,candidates,target);
            temp.pop_back();
        }
        getAllPossibleCombinations(ind + 1,curr_sum,temp,v,candidates,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int ind = 0;
        oned_vector temp;
        twod_vector v;
        int curr_sum = 0;
        getAllPossibleCombinations(ind,curr_sum,temp,v,candidates,target);
        return v;
    }
};