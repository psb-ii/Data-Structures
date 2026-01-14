class Solution {
public:
    int minAddToMakeValid(string s) {
        int curr_open = 0;
        int additions = 0;
        for(int i=0;i<s.length();i=i+1){
            if(s[i] == '(')
                curr_open++;
            else{
                if(curr_open > 0)
                    curr_open--;
                else
                    additions++;
            }
        }
        additions += curr_open;
        return additions;
    }
};