class Solution {
private:
    int subarraysWithAtleastKDifferentIntegers(vector<int>&nums,int k){
        unordered_map<int,int>freq;
        int left = 0;
        int right = 0;
        int res = 0;
        while(right < nums.size()){
            freq[nums[right]]++;
            while(freq.size() > k && right >= left){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0)
                    freq.erase(freq.find(nums[left]));
                left++;
            }
            res +=right - left + 1;
            right++;
        }
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtleastKDifferentIntegers(nums,k) - subarraysWithAtleastKDifferentIntegers(nums,k-1);
    }
};