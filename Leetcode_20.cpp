class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i=i+1){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else{
                bool flag = false;
                if(st.size() && ((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '['))){
                    flag = true;
                    st.pop();
                }
                if(!flag)
                    return false;
            } 
        }
        return st.size() == 0;
    }
};