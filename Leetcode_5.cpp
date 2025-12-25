class Solution {
private:
    void findStartOfLongestPalindromicSubstring(int l_ind,int r_ind,string &s,int &max_len,int &start){
        while(l_ind >= 0 && r_ind < s.length() && (s[l_ind] == s[r_ind])){
            cout << l_ind <<" "<< r_ind<<" "<<s[l_ind]<<" "<<s[r_ind]<<endl;
            l_ind--;
            r_ind++;
        }
        cout <<max_len <<" ";
        if(max_len < r_ind - l_ind - 1){
            max_len = r_ind - l_ind - 1;
            start = l_ind + 1;
            cout <<max_len;
        }
        cout <<endl;
    }
public:
    string longestPalindrome(string s) {
        int max_len = 0;
        int start = -1;
        int left , right;
        Solution sol;
        for(int i=0;i<s.length();i=i+1){
            left = i;
            sol.findStartOfLongestPalindromicSubstring(i,i,s,max_len,start);
            if(i + 1 < s.length()){
                right = i + 1;
                sol.findStartOfLongestPalindromicSubstring(i,i+1,s,max_len,start);
            }
        }
        cout <<start <<" "<<max_len;
        return s.substr(start,max_len);
    }
};