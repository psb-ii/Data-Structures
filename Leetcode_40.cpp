class Solution {
using twod_vector = vector<vector<int>>;
using oned_vector = vector<int>;
private:
    void getCombinations(int ind,int target,oned_vector &candidates,oned_vector &temp,twod_vector &res){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        // getCombinations(ind+1,target,candidates,temp,res);
        for(int i = ind;i < candidates.size();i = i + 1){
            if(i > ind && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            getCombinations(i+1,target-candidates[i],candidates,temp,res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int ind = 0;
        oned_vector temp;
        twod_vector res;
        getCombinations(ind,target,candidates,temp,res);
        return res;
    }
};