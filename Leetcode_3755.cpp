class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int,int>,int>ma;
        int maxi = 0;
        int count_odd = 0;
        int curr_xor = 0;
        ma[{0,0}] = -1;
        for(int i=0;i<nums.size();i=i+1){
            curr_xor = curr_xor ^ nums[i];
            count_odd +=nums[i] & 1 ? 1 : 0;
            int count_even = i + 1 - count_odd;
            int diff = count_even - count_odd;
            if(ma.find({curr_xor,diff}) == ma.end())
                ma[{curr_xor,diff}] = i;
            else
                maxi = max(maxi,(i-ma[{curr_xor,diff}]));
        }
        return maxi;
    }
};