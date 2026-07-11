class Solution {
using v_2d = vector<vector<int>>;
private:
    void completeSupersequence(int ind,string &s,string &supersequence){
        while(ind){
            supersequence +=s[ind-1];
            ind = ind - 1;
        }
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int ind1 = str1.length();
        int ind2 = str2.length();
        v_2d dp(str1.length() + 1,vector<int>(str2.length() + 1, -1));
        for(int i=0;i<=str1.length();i=i+1){
            dp[i][0] = 0;
        }
        for(int i=0;i<=str2.length();i=i+1){
            dp[0][i] = 0;
        }
        string supersequence = "";
        for(int i=1;i<=str1.length();i=i+1){
            for(int j=1;j<=str2.length();j=j+1){
                if(str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    int left_shift = dp[i-1][j];
                    int right_shift = dp[i][j-1];
                    dp[i][j] = max(left_shift,right_shift);
                }
            }
        }
        while(ind1 && ind2){
            if(str1[ind1 - 1] == str2[ind2 - 1]){
                supersequence += str1[ind1 - 1];
                ind1 = ind1 - 1;
                ind2 = ind2 - 1;
            }
            else{
                if(dp[ind1 - 1][ind2] > dp[ind1][ind2 - 1]){
                    supersequence += str1[ind1 - 1];
                    ind1 = ind1 - 1;
                }
                else{
                    supersequence += str2[ind2 - 1];
                    ind2 = ind2 - 1;
                }
            }
        }
        if(ind1)
            completeSupersequence(ind1,str1,supersequence);
        if(ind2)
            completeSupersequence(ind2,str2,supersequence);
        reverse(supersequence.begin(),supersequence.end());
        return supersequence;
    }
};