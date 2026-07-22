class Solution {
using v_2d = vector<vector<int>>;
private:
    void maxNumInTheSubarray(vector<int>&arr,v_2d &max_num,int k){
        for(int i=0;i<arr.size();i=i+1){
            int maxi = 0;
            for(int j=i;j<arr.size();j=j+1){
                if(j-i+1 > k)
                    break;
                maxi = max(maxi,arr[j]);
                max_num[i][j] = maxi;
            }
        }
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int start = 0;
        int end = 0;
        v_2d max_num(arr.size(),vector<int>(arr.size(),0));
        maxNumInTheSubarray(arr,max_num,k);
        v_2d dp(arr.size(),vector<int>(arr.size(),-1));
        for(int i=arr.size()-1;i>=0;i=i-1){
            int len = arr.size() - i;
            if(len > k)
                break;
            dp[i][arr.size()-1] = len * max_num[i][arr.size()-1];
        }
        for(int i=arr.size()-1;i>=0;i=i-1){
            int st = min(i + k - 1,int(arr.size())-2);
            for(int j=st;j>=i;j=j-1){
                int curr_len = j - i + 1;
                int taken = curr_len * max_num[i][j] + dp[j+1][j+1];
                int not_taken = 0;
                if(curr_len < k)
                    not_taken = dp[i][j+1];
                dp[i][j] = max(taken,not_taken);
            }
        }
        return dp[start][end];
    }
};