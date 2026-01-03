class Solution {
private:
    void getAllLetterCombination(int ind,string &curr,string digits,vector<string>&digit_mapper,vector<string>&vs){
        if(ind == digits.size()){
            vs.push_back(curr);
            return;
        }
        int dig = int(digits[ind]) - 48;
        for(int i=0;i<digit_mapper[dig].length();i=i+1){
            string s = curr + digit_mapper[dig][i];
            getAllLetterCombination(ind+1,s,digits,digit_mapper,vs);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>vs;
        string curr = "";
        vector<string>digit_mapper{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int ind = 0;
        getAllLetterCombination(ind,curr,digits,digit_mapper,vs);
        return vs;
    }
};