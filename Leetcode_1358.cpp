class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>ma;
        int left = 0;
        int right = 0;
        int total_valid_substrings = 0;
        while(right < s.length()){
            ma[s[right]]++;
            while(ma.size() == 3){
                total_valid_substrings += s.length() - right;
                ma[s[left]]--;
                if(ma[s[left]] == 0)
                    ma.erase(ma.find(s[left]));
                left++;
            }
            right++;
        }
        return total_valid_substrings;
    }
};