class Solution {
  using v_2d = vector<vector<int>>;
  private:
    int maxLengthOfLongestCommonSubstring(int ind1,int ind2,string &s1,string &s2,v_2d &dp){
        if(ind1 == 0 || ind2 == 0)
            return 0;
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if(s1[ind1 - 1] == s2[ind2 - 1])
            return dp[ind1][ind2] = 1 + maxLengthOfLongestCommonSubstring(ind1-1,ind2-1,s1,s2,dp);
        else
            return dp[ind1][ind2] = 0;
    }
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int ind1 = s1.length();
        int ind2 = s2.length();
        v_2d dp(s1.length() + 1,vector<int>(s2.length() + 1,-1));
        int res = 0;
        for(int i=1;i<=s1.length();i=i+1){
            for(int j=1;j<=s2.length();j=j+1){
                int maxLen = maxLengthOfLongestCommonSubstring(i,j,s1,s2,dp);
                res = max(res,maxLen);
            }
        }
        return res;
    }
};