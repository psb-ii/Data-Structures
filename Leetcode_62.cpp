class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(m,0);
        prev[0]=1;
        const int MOD = 2 * 1e9;
        for(int i=0;i<n;i=i+1){
            vector<int>curr(m,0);
            curr[0]=1;
            for(int j=0;j<m;j=j+1){
                if(i | j){
                    int up = 0;
                    int left = 0;
                    if(i - 1 >= 0)
                        up = prev[j];
                    if(j - 1 >= 0)
                        left = curr[j-1];
                    curr[j] = (1ll*up + 1ll*left) % MOD;
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};