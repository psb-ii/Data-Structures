class Solution {
using v_2d = vector<vector<int>>;
private:
    bool isStringPalindromeOrNot(string& s){
        int i = 0;
        int j = s.length() - 1;
        while(i <= j){
            if(s[i] != s[j])
                return false;
            i +=1;
            j -=1;
        }
        return true;
    }
public:
    int minCut(string s) {
        v_2d pall_map(s.length(),vector<int>(s.length(),0));
        for(int i=0;i<s.length();i=i+1){
            string temp = "";
            for(int j=i;j<s.length();j=j+1){
                temp +=s[j];
                if(isStringPalindromeOrNot(temp))
                    pall_map[i][j] = 1;
            }
        }
        int start = 0;
        int end = 0;
        v_2d dp(s.length(),vector<int>(s.length(),-1));
        for(int i=0;i<s.length();i=i+1){
            if(pall_map[i][s.length() - 1] == 1)
                dp[i][s.length() - 1] = 0;
            else
                dp[i][s.length() - 1] = 1e9;
        }
        for(int i=s.length()-1;i>=0;i=i-1){
            for(int j=s.length()-2;j>=i;j=j-1){
                int taken = INT_MAX;
                int not_taken = dp[i][j+1];
                if(pall_map[i][j] == 1)
                    taken = 1 + dp[j+1][j+1];
                dp[i][j] = min(taken,not_taken);
            }
        }
        return dp[start][end];
    }
};