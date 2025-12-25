class Solution {
private: 
    static bool compare(int a, int b){
        return a > b;
    }
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),compare);
        long long max_happiness = 0ll;
        for(int i=0;i<k;i=i+1){
            max_happiness += 1ll*(happiness[i] - i > 0) ? happiness[i] - i : 0;
        }
        return max_happiness;
    }
};