class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        int prev = 1;
        long long int res = 1;
        int seat_count = 0;
        for(int i=0;i<corridor.size();i=i+1){
            if(corridor[i] == 'S'){
                seat_count++;
                if(seat_count > 2 && (seat_count & 1)){
                    res = (res * prev) % MOD;
                }
                if(seat_count > 2 && ((seat_count & 1) == 0))
                    prev = 1;
            }
            else{
                if(((seat_count & 1) == 0) && seat_count >= 2)
                    prev +=1;
            }
        }
        if((seat_count & 1) || seat_count == 0)
            return 0;
        return res;
    }
};