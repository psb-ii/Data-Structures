class Solution {
private:
    void update(vector<int>&coins,vector<int>&prev,int amount){
        for(int i=0;i<coins.size();i=i+1){
            for(int j=1;j<=amount;j=j+1){
                if(j % coins[i] == 0)
                    prev[j] = j / coins[i];
                else
                    prev[j] = 1e8;
            }
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ind = coins.size()-1;
        vector<int>prev(amount+1,-1);
        prev[0]=0;
        update(coins,prev,amount);
        vector<int>curr(amount+1,-1);
        curr[0]=0;
        update(coins,curr,amount);
        for(int i=0;i<coins.size();i=i+1){
            for(int j=1;j<=amount;j=j+1){
                int not_taken = prev[j];
                int taken = 1e8;
                if(j >= coins[i])
                    taken = 1 + curr[j-coins[i]];
                curr[j] = min(taken,not_taken);
            }
            prev = curr;
        }
        if(prev[amount] >= 1e8)
            return -1;
        return prev[amount];
    }
};