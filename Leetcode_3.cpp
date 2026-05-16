class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int i=0;
        int j=0;
        unordered_set<char>se;
        while(j<s.length()){
            se.insert(s[j]);
            if(se.size() == j-i+1)
                res = max(res,j-i+1);
            else{
                while(j-i+1 != se.size()){
                    if(s[i] != s[j])
                        se.erase(se.find(s[i]));
                    i++;
                }
            }
            j++;
        }
        return res;
    }
};