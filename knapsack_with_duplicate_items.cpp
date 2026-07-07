class Solution {
  using v_2d = vector<vector<int>>;
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        v_2d dp(val.size(),vector<int>(capacity+1,-1));
        vector<int>prev(capacity+1,-1);
        int ind = val.size() - 1;
        for(int i = 0;i<=capacity;i=i+1){
            prev[i] = (i / wt[0]) * val[0];
        }
        vector<int>curr = prev;
        for(int i=1;i<wt.size();i=i+1){
            for(int j=0;j<=capacity;j=j+1){
                int taken = 0;
                int not_taken = prev[j];
                if(j >= wt[i])
                    taken = val[i] + curr[j-wt[i]];
                curr[j] = max(taken,not_taken);
            }
            prev = curr;
        }
        return prev[capacity];
    }
};