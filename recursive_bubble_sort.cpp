class Solution {
private:
    void recursiveBubbleSort(vector<int>&nums,int pos){
        if(pos == 0)
            return 
        for(int i=0;i<=pos;i=i+1){
            if(nums[i]>nums[i+1])
                swap(nums[i],nums[i+1]);
        }
        recursiveBubbleSort(nums,pos-1);
    }
public:
    vector<int> bubbleSort(vector<int>& nums) {
        int pos = nums.size() - 1;
        recursiveBubbleSort(nums,pos);
        return nums;
    }
};