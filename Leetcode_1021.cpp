class Solution {
public:
    string removeOuterParentheses(string s) {
        string rem_s = "";
        int open_braces = 0;
        for(int i=0;i<s.length();i=i+1){
            open_braces += s[i] == '(' ? 1 : -1;
            if(s[i] == '(' && open_braces > 1)
                rem_s += '(';
            if(s[i] == ')' && open_braces)
                rem_s += ')'; 
        }
        return rem_s;
    }
};