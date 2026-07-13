class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ind = 0;
        int buy = 1;
        vector<int>ahead1(2,-1);
        ahead1[0]=0;
        ahead1[1]=0;
        vector<int>ahead2 = ahead1;
        vector<int>curr = ahead1;
        for(int i=prices.size()-1;i>=0;i=i-1){
            for(int j=0;j<=1;j=j+1){
                int profit = 0;
                if(j){
                    profit = max(-1 * prices[i] + ahead1[0],ahead1[j]);
                }
                else{
                    int next_day = i + 2 <= prices.size() ? i + 2 : prices.size();
                    profit = max(prices[i] + ahead2[1],ahead1[j]); 
                }
                curr[j] = profit;
            }
            ahead2 = ahead1;
            ahead1 = curr;
        }
        return ahead1[buy];
    }
};