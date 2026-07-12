class Solution {
public:
    bool isMatch(string s, string p) {
        int ind1 = s.length();
        int ind2 = p.length();
        vector<bool>prev(p.length() + 1,false);
        int current = true;
        for(int i=1;i<=p.length();i=i+1){
            if(p[i-1] != '*')
                current = false;
            prev[i] = current;
        }
        vector<bool>curr = prev;
        prev[0] = true;
        for(int i=1;i<=s.length();i=i+1){
            curr[0] = false;
            for(int j=1;j<=p.length();j=j+1){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    curr[j] = prev[j-1];
                else
                if(p[j - 1] == '*'){
                    int shift_left = prev[j];
                    int shift_right = curr[j-1];
                    int shift_both = prev[j-1];
                    curr[j] = shift_left | shift_right | shift_both;
                }
                else{
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[ind2];
    }
};