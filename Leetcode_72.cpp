class Solution {
public:
    int minDistance(string word1, string word2) {
        int ind1 = word1.length();
        int ind2 = word2.length();
        vector<int>prev(word2.length() + 1,0);
        for(int i=0;i<=word2.length();i=i+1){
            prev[i] = i;
        }
        vector<int>curr = prev;
        for(int i=1;i<=word1.length();i=i+1){
            curr[0] = i;
            for(int j=1;j<=word2.length();j=j+1){
                int val = 0;
                if(word1[i - 1] == word2[j - 1])
                    curr[j] = prev[j-1];
                else{
                    int insert = 1 + curr[j-1];
                    int replace = 1 + prev[j-1];
                    int delet = 1 + prev[j];
                    curr[j] = min({insert,replace,delet});
                }
            }
            prev = curr;
        }
        return prev[ind2];
    }
};