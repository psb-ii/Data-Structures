class Solution {
  using v_3d = vector<vector<vector<int>>>;
  private:
    int numberOfWaysToEvaluateToTrue(int i,int j,int isTrue,string &s,v_3d &dp){
        if(i > j)
            return 0;
        if(i == j){
            if(isTrue)
                return s[i] == 'T' ? 1 : 0;
            else
                return s[i] == 'F' ? 1 : 0;
        }
        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        int ways = 0;
        for(int ind = i + 1;ind < j;ind = ind + 2){
            int lT = numberOfWaysToEvaluateToTrue(i,ind-1,1,s,dp);
            int rT = numberOfWaysToEvaluateToTrue(ind+1,j,1,s,dp);
            int lF = numberOfWaysToEvaluateToTrue(i,ind-1,0,s,dp);
            int rF = numberOfWaysToEvaluateToTrue(ind+1,j,0,s,dp);
            if(s[ind] == '&'){
                if(isTrue){
                    ways = ways + lT * rT;
                }
                else{
                    ways = ways + lT * rF + lF * rT + lF * rF;
                }
            }
            else
            if(s[ind] == '|'){
                if(isTrue){
                    ways = ways + lT * rT + lT * rF + lF * rT;
                }
                else{
                    ways = ways + lF * rF;
                }
            }
            else{
                if(isTrue){
                    ways = ways +lT * rF + lF * rT;
                }
                else{
                    ways = ways + lT * rT + lF * rF;
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }
  public:
    int countWays(string &s) {
        // code here
        int start = 0;
        int end = s.length() - 1;
        int isTrue = 1;
        v_3d dp(s.length(),vector<vector<int>>(s.length(),vector<int>(2,-1)));
        return numberOfWaysToEvaluateToTrue(start,end,isTrue,s,dp);
    }
};