class Solution {
private:
    int query(vector<int>&bit,int num){
        int count = 0;
        for(int i = num;i > 0;i -= i&(-i)){
            count +=bit[i];
        }
        return count;
    }
    void update(vector<int>&bit,int num){
        for(int i = num;i < bit.size(); i += i&(-i)){
            bit[i] = bit[i] + 1;
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>bit(((2*1e4) + 2),0);
        vector<int>lesser(nums.size(),0);
        for(int i = nums.size() - 1;i >= 0;i = i - 1){
            // cout <<i<<endl;
            int lesser_numbers = query(bit,nums[i] + 1e4);
            // cout <<lesser_numbers<<endl;
            lesser[i] = lesser_numbers;
            update(bit,nums[i] + 1e4 + 1);
        }
        return lesser;
    }
};