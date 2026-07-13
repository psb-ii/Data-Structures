class Solution {
using v_2d = vector<vector<int>>;
public:
    int maxProfit(vector<int>& prices) {
        int ind = 0;
        int buy = 0;
        vector<int>ahead(5,-1);
        for(int i=0;i<=4;i=i+1){
            ahead[i]=0;
        }
        vector<int>curr = ahead;
        for(int i=prices.size()-1;i>=0;i=i-1){
            for(int j=0;j<4;j=j+1){
                int profit = 0;
                if((j & 1) == 0){
                    profit = max(-1 * prices[i] + ahead[j+1],ahead[j]);
                }
                else{
                    profit = max(prices[i] + ahead[j+1],ahead[j]);
                }
                curr[j] = profit;
            }
            ahead = curr;
        }
        return ahead[buy];
    }
};