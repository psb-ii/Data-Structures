class Solution {
private:
    static bool cmp(string &a,string &b){
        return a.length() < b.length();
    }
public:
    int longestStrChain(vector<string>& words) {
        vector<int>dp(words.size(),1);
        sort(words.begin(),words.end(),cmp);
        int maxi = 1;
        for(int i=1;i<words.size();i=i+1){
            for(int j=0;j<i;j=j+1){
                if(words[i].length() - words[j].length() == 1){
                    int ptr1 = 0;
                    int ptr2 = 0;
                    while(ptr1 < words[i].length() && ptr2 < words[j].length()){
                        if(words[i][ptr1] == words[j][ptr2]){
                            ptr1++;
                            ptr2++;
                        }
                        else{
                            ptr1++;
                        }
                    }
                    if((ptr1 == words[i].length() && ptr2 == words[j].length()) || (ptr1 == words[i].length() -1)){
                        dp[i] = max(dp[i],dp[j] + 1);
                    }
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};