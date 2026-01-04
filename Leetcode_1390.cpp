class Solution {
private:
    void generateSmallestDivisor(vector<int>&sd){
        for(int i = 2;i*i <= 1e5;i=i+1){
            if(sd[i] == i){
                sd[i] = i;
                for(int j = i*i ;j <= 1e5; j=j+i){
                    if(sd[j] == j)
                        sd[j] = i;
                }
            }
        }
    }
    int calculateFourDivisorSum(int num,vector<int>&sd){
        int count = 0;
        int sum = 1;
        int p = 1;
        int div = 0;
        int prev = 0;
        int total = 1;
        while(num > 1){
            div = sd[num];
            num = num/sd[num];
            if(div != prev){
                p *=sum;
                total *=(1+count); 
                count=1;
                sum = 1 + div;
                prev = div;
            }
            else{
                count++;
                sum += pow(div,count);
            }
        }
        p *=sum; 
        total *=(1+count);
        if(total == 4)
            return p;
        return 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        vector<int>sd(1e5 + 1,1);
        for(int i=0;i<=1e5;i=i+1){
            sd[i]=i;
        }
        generateSmallestDivisor(sd);
        int four_sum_divisors = 0;
        long long int sum = 0;
        // cout <<sd[4713];
        for(int i=0;i<nums.size();i=i+1){
            sum +=1ll*calculateFourDivisorSum(nums[i],sd);
        }
        return sum;
    }
};