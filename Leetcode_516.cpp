class Solution {
using v_2d = vector<vector<int>>;
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int ind1 = s1.length();
        int ind2 = s2.length();
        v_2d dp(s.length()+1,vector<int>(s.length()+1,-1));
        for(int i=0;i<=s.length();i=i+1){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for(int i=1;i<=s.length();i=i+1){
            for(int j=1;j<=s.length();j=j+1){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    int left_shift = dp[i-1][j];
                    int right_shift = dp[i][j-1];
                    dp[i][j] = max(left_shift,right_shift);
                }
            }
        }
        return dp[ind1][ind2];
    }
};