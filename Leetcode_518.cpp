class Solution {
using v_2d = vector<vector<int>>;
public:
    int change(int amount, vector<int>& coins) {
        int ind = coins.size() - 1;
        vector<int>prev(amount+1,0);
        for(int i=0;i<=amount;i=i+1){
            if(i % coins[0] == 0)
                prev[i] = 1;
        }
        vector<int>curr = prev;
        for(int i=1;i<coins.size();i=i+1){
            for(int j=0;j<=amount;j=j+1){
                int taken = 0;
                int not_taken = prev[j];
                if(j >= coins[i])
                    taken = curr[j-coins[i]];
                curr[j] = 1ll*taken + 1ll*not_taken;
            }
            prev = curr;
        }
        return prev[amount];
    }
};