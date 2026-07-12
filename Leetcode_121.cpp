class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int curr_max = prices[prices.size() - 1];
        for(int i=prices.size()-2;i>=0;i=i-1){
            maxi = max(maxi,curr_max - prices[i]);
            curr_max = max(curr_max,prices[i]);
        }
        return maxi;
    }
};