class Solution {
private:
    bool isPossible(string &s,string &ss,string &word){
        // bool flag = true;
        for(int i=0;i<min(s.length(),ss.length());i=i+1){
            if(s[i] != ss[i])
                return false;
        }
        if(ss.length() > s.length()){                            // "aabbaaba" 2
            for(int i=s.length();i<ss.length();i=i+1){
                if(ss[i] != word[i])
                    return false;
            }
        }
        return true;
    }
public:
    int minimumTimeToInitialState(string word, int k) {
        string s="";
        string ss="";
        for(int i=0;i<word.length()/k;i=i+1){
            s = word.substr(0,k*(i+1));
            int rem_len = word.length() - (k*(i+1));
            ss = word.substr(k*(i+1),rem_len);
            if(isPossible(s,ss,word)){
                return i+1;
            }
        }
        return word.length()/k + 1;
    }
};