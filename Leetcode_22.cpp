class Solution {
private:
    void generateAllPossibleParenthesesCombination(int open,int closed,int n,string &s,vector<string>&v){
        if(closed == n){
            v.push_back(s);
            return;
        }
        string temp = s + "(";
        if(open + 1 <= n)
            generateAllPossibleParenthesesCombination(open + 1,closed,n,temp,v);
        if(closed < open){
            temp = s + ")";
            generateAllPossibleParenthesesCombination(open,closed + 1,n,temp,v);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int open = 0, closed = 0;
        string s = "";
        vector<string>v;
        generateAllPossibleParenthesesCombination(open,closed,n,s,v);
        return v;
    }
};