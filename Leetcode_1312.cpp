class Solution {
using v_2d = vector<vector<int>>;
public:
    int minInsertions(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int ind1 = s1.length();
        int ind2 = s2.length();
        vector<int>prev(s.length()+1,-1);
        for(int i=0;i<=s.length();i=i+1){
            prev[i] = 0;
        }
        vector<int>curr = prev;
        for(int i=1;i<=s.length();i=i+1){
            for(int j=1;j<=s.length();j=j+1){
                if(s1[i-1] == s2[j-1])
                    curr[j] = 1 + prev[j-1];
                else{
                    int left_shift = prev[j];
                    int right_shift = curr[j-1];
                    curr[j] = max(left_shift,right_shift);
                }
            }
            prev = curr;
        }
        return s.length() - prev[ind2];
    }
};