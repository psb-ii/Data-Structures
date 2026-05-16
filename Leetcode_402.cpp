class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.length();i=i+1){
            while(k > 0 && st.size() && st.top() > num[i]){
                k = k - 1;
                st.pop();
            }
            st.push(num[i]);
        }
        while(st.size() && k){
            k = k - 1;
            st.pop();
        }
        string s = "";
        while(st.size()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        int i = 0;
        while(i < s.length() && s[i] == '0'){
            i++;
        }
        s = i < s.length() ? s.substr(i,s.length() - i) : "0";
        return s;
    } 
};