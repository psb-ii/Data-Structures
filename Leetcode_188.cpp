class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int ind = 0;
        int trans_count = 0;
        vector<int>ahead(2*k+1,-1);
        for(int i=0;i<=2*k;i=i+1){
            ahead[i] = 0;
        }
        vector<int>curr = ahead;
        for(int i=prices.size()-1;i>=0;i=i-1){
            for(int j=0;j<2*k;j=j+1){
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
        return ahead[trans_count];
    }
};