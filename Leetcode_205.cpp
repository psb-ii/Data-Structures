class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() == t.length()){
            unordered_map<char,char>ma;
            unordered_set<char>se;
            for(int i=0;i<s.length();i=i+1){
                if(ma.find(s[i]) == ma.end() && se.find(t[i]) == se.end()){
                    ma[s[i]] = t[i];
                    se.insert(t[i]);
                }
                else
                if(ma[s[i]] != t[i])
                    return 0;
            }
            return 1;
        }
        return 0;
    }
};