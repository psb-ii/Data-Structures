class Solution {
private: 
    int calculateNumberOfPrime(vector<int>&prime, int n){
        int k = 0;
        for(int i=0;i<prime.size() && prime[i] < n;i=i+1){
            k += prime[i] < n ? 1 : 0;
        }
        return k;
    }
public:
    int countPrimes(int n) {
        // const int num = (5 * 1e6) + 1;
        vector<bool>isPrimes(n + 1,true);
        isPrimes[1] = false;
        vector<int>prime;
        for(int i = 2; i*i <= n; i = i + 1){
            if(isPrimes[i]){
                prime.push_back(i);
                for(int j = i*i; j <= n; j +=i){
                    isPrimes[j] = false;
                }
            }
        }
        return calculateNumberOfPrime(prime,n);
    }
};