class Solution {
private:
    string sayItAgain(int n){
        if(n == 1)
            return "1";
        string s = sayItAgain(n-1);
        string rle = "";
        char prev = s[0];
        int count = 1;
        for(int i=1;i<s.length();i=i+1){
            if(s[i] == prev)
                count++;
            else{
                rle += to_string(count) + to_string(prev - '0');
                count = 1;
                prev = s[i];
            }
        }
        rle += to_string(count) + to_string(prev - '0');
        return rle;
    }
public:
    string countAndSay(int n) {
        return sayItAgain(n);