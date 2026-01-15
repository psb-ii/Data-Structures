class Solution {
public:
    bool checkValidString(string s) {
        int curr_min = 0;
        int curr_max = 0;
        for(int i=0;i<s.length();i=i+1){
            if(s[i] == '('){
                curr_min +=1;
                curr_max +=1;
            }
            else
            if(s[i] == ')'){
                curr_min -=1;
                curr_max -=1;
            }
            else{
                curr_min -=1;
                curr_max +=1;
            }
            if(curr_min < 0)
                curr_min = 0;
            if(curr_max < 0)
                return false;
        }
        return curr_min == 0;
    }
};
