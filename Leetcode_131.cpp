class Solution {
using oned_vector = vector<string>;
using twod_vector = vector<vector<string>>;
private:
    bool isPalindrome(string &s){
        // cout <<s<<" ";
        for(int i=0;i<s.length()/2;i=i+1){
            if(s[i] != s[s.length()-i-1])
                return false;
        }
        return true;
    }
    void getAllPartitionedPalindromes(int ind,string &curr_s,string &s,oned_vector &curr,twod_vector &vs){
        if(ind == s.length()){
            if(isPalindrome(curr_s)){
                if(curr_s.length())
                    curr.push_back(curr_s);
                vs.push_back(curr);
                if(curr_s.length())
                    curr.pop_back();
            }
            return;
        }
        string k = curr_s + s[ind];
        getAllPartitionedPalindromes(ind+1,k,s,curr,vs);
        if(curr_s.length() && isPalindrome(curr_s)){
            curr.push_back(curr_s);
            k = "";
            k.push_back(s[ind]);
            getAllPartitionedPalindromes(ind+1,k,s,curr,vs);
            curr.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int ind = 0;
        oned_vector curr;
        twod_vector vs;
        string curr_s = "";
        getAllPartitionedPalindromes(ind,curr_s,s,curr,vs);
        return vs;
    }
};