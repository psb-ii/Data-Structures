class Solution {
private:
    long long int getPower(int n,long long int p){
        const int mod = 1e9 + 7;
        if(p == 0)
            return 1;
        else{
            if(p & 1)
                return ((n * (getPower(n,p-1) % mod)) % mod);
            else
                return (getPower((1ll*n*n)%mod, (p>>1)) % mod);
        }
    }
public:
    int countGoodNumbers(long long n) {
        const int mod = 1e9 + 7;
        long long int res = ((getPower(5,((n+1) >> 1)) % mod) * (getPower(4,(n >> 1)) % mod)) % mod;
        return res;
    }
};