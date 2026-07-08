class Solution {
using v_2d = vector<vector<int>>;
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ind1 = text1.length();
        int ind2 = text2.length();
        vector<int>prev(text2.size()+1,0);
        vector<int>curr = prev;
        for(int i=0;i<=ind2;i=i+1)
            prev[i] = 0;
        for(int i=1;i<=ind1;i=i+1){
            for(int j=1;j<=ind2;j=j+1){
                if(text1[i-1] == text2[j-1])
                    curr[j] = 1 + prev[j-1];
                else{
                    int left_shift = prev[j];
                    int right_shift = curr[j-1];
                    curr[j] = max(left_shift,right_shift);
                }
            }
            prev = curr;
        }
        return prev[ind2];
    }
};