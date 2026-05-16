class Solution {
private:
    void updateBits(vector<int>&bits,vector<int>&nums){
        for(int i=0;i<nums.size();i=i+1){
            int k = nums[i];
            int bit = 0;
            while(k){
                bits[bit] += k & 1 ? 1 : 0;
                k = k >> 1;
                bit +=1;
            }
        }
    }
    long long int getBitwiseOrValue(vector<int>&bits){
        long long int k = 0ll;
        for(int i=0;i<bits.size();i=i+1){
            k += bits[i] ? (long long)(1ll<<i) : 0;
        }
        return k;
    }
    void subtraction(vector<int>&bits,long long int num){
        int bit = 0;
        while(num){
            bits[bit] -= (num & 1) ? 1 : 0;
            num = num >> 1;
            bit +=1;
        }
    }
    void addition(vector<int>&bits,long long int num){
        int bit = 0;
        // cout <<num<<endl;
        while(num){
            bits[bit] += (num & 1)? 1 : 0;
            num = num >> 1;
            bit +=1;
        }
    }
public:
    long long maximumOr(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end(),comp);
        // vector<long long int>n;
        // for(auto num : nums){
        //     n.emplace_back(1ll*num);
        // }
        vector<int>bits(50,0);
        updateBits(bits,nums);
        long long int maxi_or=getBitwiseOrValue(bits);
        // for(int i=0;i<10;i=i+1){
        //     cout <<bits[i]<<" ";
        // }
        // cout <<endl;
        int changed = 0;
        for(int i=0;i<nums.size();i=i+1){
            long long int kk = 1ll*nums[i];
            subtraction(bits,kk);
            addition(bits, (kk << k));
            long long int curr_or = getBitwiseOrValue(bits);
            // cout <<"a";
            if(curr_or > maxi_or){
                maxi_or = curr_or;
                changed = i;
            }
            addition(bits,kk);
            subtraction(bits,kk << k);
        }
        subtraction(bits,1ll*nums[changed]);
        addition(bits,(1ll*nums[changed] << k));
        long long int result = getBitwiseOrValue(bits);
        return result;
    }
};