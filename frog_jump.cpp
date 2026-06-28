class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        long long int prev1 = 0ll;
        long long int prev2 = 0ll;
        long long int curr = 0ll;
        for(int i=1;i<height.size();i=i+1){
            long long int one_step = 1ll*abs(height[i] - height[i-1]) + prev1;
            long long int two_step = 1e18;
            if(i > 1)
                two_step = 1ll*abs(height[i] - height[i-2]) + prev2;
            curr = 1ll*min(one_step,two_step);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};