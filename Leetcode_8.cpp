class Solution {
private:
    int getFirstNonWhitespaceInString(string &s){
        for(int i=0;i<s.length();i=i+1){
            if((s[i] != ' '))
                return i;
        }
        return s.length();
    }
public:
    int myAtoi(string s) {
        Solution sol;
        long long int num = 0;
        bool flag = 0;
        bool is_flag_set = 0;
        int first_place = sol.getFirstNonWhitespaceInString(s);
        s = s.substr(first_place,s.length() - first_place + 1);
        for(int i=0;i<s.length();i=i+1){
            int ascii_code = int(s[i]);
            if(is_flag_set && !((ascii_code >= 48 && ascii_code <58)))
                return num;
            if(s[i] == '-'){
                flag = 1;
                is_flag_set = 1;
            }
            else
            if(s[i] == '+'){
                is_flag_set = 1;
                flag = 0;
            }
            else
            if(ascii_code >= 48 && ascii_code <58){
                while(i<s.length() && int(s[i])>=48 && int(s[i])<58){
                    int digit = int(s[i]) - 48;
                    if(flag)
                        digit *=-1ll;
                    num = num*10 + 1ll*digit;
                    if(num <= INT_MIN)
                        return INT_MIN;
                    else
                    if(num >= INT_MAX)
                        return INT_MAX;
                    i++;
                }
                return num;
            }
            else
                return num;
        }
        return num;
    }
};