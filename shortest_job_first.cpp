class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        long long int total_wt = 0ll;
        long long int curr_time = 0ll;
        for(int i=0;i<bt.size();i +=1){
            total_wt +=curr_time;
            curr_time +=1ll*bt[i];
        }
        return total_wt/bt.size();
    }
};