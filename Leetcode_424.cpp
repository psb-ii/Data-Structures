class Solution {
private:
    int getMaximumFrequency(unordered_map<char,int>&ma){
        int maxi = 0;
        for(auto it = ma.begin();it != ma.end();it++){
            maxi = max(maxi,it->second);
        }
        return maxi;
    }
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>ma;
        int left = 0;
        int right = 0;
        int res = 0;
        int max_freq = 0;
        while(right < s.length()){
            ma[s[right]]++;
            max_freq = max(max_freq,ma[s[right]]);
            int remaining = right - left + 1 - max_freq;
            if(remaining > k){
                ma[s[left]]--;
                left++;
            }
            if(remaining <= k)
                res = max(res,right - left + 1);
            right++;
        }
        return res;
    }
};