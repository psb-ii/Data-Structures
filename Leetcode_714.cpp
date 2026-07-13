class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ind = 0;
        int buy = 1;
        vector<int>ahead(2,-1);
        ahead[0] = 0;
        ahead[1] = 0;
        vector<int>curr = ahead;
        for(int i=prices.size()-1;i>=0;i=i-1){
            for(int j=0;j<=1;j=j+1){
                int profit = 0;
                if(j){
                    profit = max(-1 * prices[i] + ahead[0],ahead[j]);
                }
                else{
                    profit = max(prices[i] - fee + ahead[1], ahead[j]);
                }
                curr[j] = profit;
            }
            ahead = curr;
        }
        return ahead[buy];
    }
};