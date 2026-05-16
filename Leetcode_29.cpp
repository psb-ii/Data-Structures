class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = false;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = true;
        long long int divi = llabs(dividend); // use llabs to convert INT_MIN into positive as usual integer will overflow
        long long int diso = llabs(divisor);
        long long quotient = 0ll;
        long long int rema = divi;
        int p = 31;
        while(rema >=diso){
            long long int po = 1ll << p;
            // cout <<rema<<" "<<po<<endl;
            if(rema >= (po*diso)){
                rema -=(po*diso);
                quotient +=po;
            }
            p--;
        }
        if(sign)
            quotient = -1*quotient;
        if(quotient >= INT_MAX)
            return INT_MAX;
        if(quotient < INT_MIN)
            return INT_MIN;
        return quotient;
    }
};