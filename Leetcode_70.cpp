class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int last = 1;
        int sec_last = 1;
        int curr = 1;
        for(int i=2;i<=n;i=i+1){
            curr = last + sec_last;
            sec_last = last;
            last = curr;
        }
        return curr;
    }
};