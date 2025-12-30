class Solution{
private:
    vector<int> update(long long int bit, vector<int> &nums)
    {
        int setbit = 0;
        int notset = 0;
        for (int i = 0; i < nums.size(); i = i + 1)
        {
            if (nums[i] & bit)
                setbit ^= nums[i];
            else
                notset ^= nums[i];
        }
        // cout <<setbit <<" "<<notset<<endl;
        vector<int> res{setbit, notset};
        sort(res.begin(), res.end());
        return res;
    }
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int resultant_xor = 0;
        for (int i = 0; i < nums.size(); i = i + 1)
        {
            resultant_xor ^= nums[i];
        }
        resultant_xor = -1ll * resultant_xor;
        long long int right_bit = resultant_xor & (-1ll * resultant_xor);
        // cout <<right_bit<<endl;
        return update(right_bit, nums);
    }
};