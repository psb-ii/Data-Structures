class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>se;
        for(int i=0;i<nums.size();i=i+1){
            se.insert(nums[i]);
        }
        int max_chain = 0;
        for(int i=0;i<nums.size();i=i+1){
            int curr = nums[i];
            int num = nums[i];
            int curr_chain = 0;
            while(se.find(num) != se.end()){
                se.erase(se.find(num));
                num++;
                curr_chain++;
            }
            num = nums[i] - 1;
            while(se.find(num) != se.end()){
                se.erase(se.find(num));
                num--;
                curr_chain++;
            }
            max_chain = max(max_chain,curr_chain);
        }
        return max_chain;
    }
};