class Solution {
  using v_2d = vector<vector<int>>;
  public:
    int cutRod(vector<int> &price) {
        // code here
        vector<int>prev(price.size() + 1,-1);
        int ind = price.size() - 1;
        for(int i=0;i<=price.size();i=i+1){
            prev[i] = i * price[0];
        }
        vector<int>curr = prev;
        for(int i=1;i<price.size();i=i+1){
            for(int j=0;j<=price.size();j=j+1){
                int taken = 0;
                int not_taken = prev[j];
                if(j >= i + 1)
                    taken = price[i] + curr[j-i-1];
                curr[j] = max(taken,not_taken);
            }
            prev = curr;
        }
        return prev[price.size()];
    }
};