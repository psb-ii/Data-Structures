class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int res = 0;
        unordered_map<int,int>ma;
        while(right < fruits.size()){
            ma[fruits[right]]++;
            while(ma.size() > 2){
                ma[fruits[left]]--;
                if(ma[fruits[left]] == 0){
                    ma.erase(ma.find(fruits[left]));
                }
                left++;
            }
            res = max(res,right-left+1);
            right++;
        }
        return res;
    }
};