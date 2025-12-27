class Solution {
private:
    bool isPossible(vector<int>&weights,int max_weight,int days){
        int total_days = 0;
        int curr_weight = 0;
        for(int i=0;i<weights.size();i=i+1){
            curr_weight +=weights[i];
            if(curr_weight >= max_weight){
                total_days++;
                curr_weight = curr_weight > max_weight ? weights[i] : 0;
            }
        }
        if(curr_weight)
            total_days++;
        return total_days <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high = accumulate(weights.begin(),weights.end(),0);
        int low = *max_element(weights.begin(),weights.end());
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(isPossible(weights,mid,days))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};