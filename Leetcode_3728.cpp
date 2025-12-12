class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        map<pair<int, long long>,long long>ma;
        long long int sum = 0;
        long long int stable_subarrays = 0;
        for(int i=0;i<capacity.size();i=i+1){
            sum +=capacity[i];
            if(ma.find({capacity[i],(sum-2*capacity[i])}) != ma.end()){
                stable_subarrays +=ma[{capacity[i],sum-2*capacity[i]}];
                if(i-1>=0 && capacity[i] == 0 && capacity[i-1] == 0)
                    stable_subarrays--;
            }
            ma[{capacity[i],sum}]++;
        }
        return stable_subarrays;
    }
};