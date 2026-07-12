class Solution {
using v_2d = vector<vector<double>>;
public:
    int numDistinct(string s, string t) {
        int ind1 = s.length();
        int ind2 = t.length();
        vector<double>prev(t.length()+1,0);
        prev[0] = 1;
        for(int i=1;i<=s.length();i=i+1){
            for(int j=t.length();j>0;j=j-1){
                double taken = 0;
                double not_taken = 0;
                if(s[i-1] == t[j-1]){
                    prev[j] = prev[j-1] + prev[j];
                }
            }
        }
        return int(prev[ind2]);
    }
};