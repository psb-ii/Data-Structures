class Solution {
public:
    int minDistance(string word1, string word2) {
        string s1 = word1;
        string s2 = word2;
        int ind1 = s1.length();
        int ind2 = s2.length();
        vector<int>prev(s2.length()+1,-1);
        for(int i=0;i<=s2.length();i=i+1){
            prev[i] = 0;
        }
        vector<int>curr = prev;
        for(int i=1;i<=s1.length();i=i+1){
            for(int j=1;j<=s2.length();j=j+1){
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
        return s2.length() + s1.length() - 2*prev[ind2];
    }
};