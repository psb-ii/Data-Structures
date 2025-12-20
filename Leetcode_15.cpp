class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        unordered_map<int,int>ma;
        for(int i=0;i<nums.size();i=i+1){
            ma[nums[i]]++;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();){
            int num = nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                int curr_sum = num + nums[left] + nums[right];
                if(curr_sum < 0)
                    left++;
                else
                if(curr_sum > 0)
                    right--;
                else{
                    vector<int>v{num,nums[left],nums[right]};
                    res.push_back(v);
                    int left_ele = nums[left];
                    int right_ele = nums[right];
                    while(left + 1 < right && nums[left + 1] == left_ele)
                        left +=1;
                    while(right - 1 > left && nums[right - 1] == right_ele)
                        right -=1;
                    left +=1;
                    right -=1;
                }
            }
            i +=ma[nums[i]];
        }
        return res;
    }
};