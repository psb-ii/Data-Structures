class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        unordered_map<char,int>ma;
        int left = 0;
        int right = 0;
        int res = 0;
        while(right < s.length()){
            ma[s[right]]++;
            while(ma.size()>k){
                ma[s[left]]--;
                if(ma[s[left]] == 0){
                    ma.erase(ma.find(s[left]));
                }
                left++;
            }
            res = max(res,right-left+1);
            right +=1;
        }
        return res;
    }
};