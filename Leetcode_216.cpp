class Solution {
using oned_vector = vector<int>;
using twod_vector = vector<vector<int>>;
private:
    void getCombinations(int curr,int k,int sum,oned_vector &temp,twod_vector &res){
        if(curr == 10){
            if(sum == 0 && (temp.size() == k))
                res.push_back(temp);
            return;
        }
        getCombinations(curr+1,k,sum,temp,res);
        if(sum >= curr){
            temp.push_back(curr);
            getCombinations(curr+1,k,sum-curr,temp,res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int curr = 1;
        oned_vector temp;
        twod_vector res;
        getCombinations(curr,k,n,temp,res);
        return res;
    }
};