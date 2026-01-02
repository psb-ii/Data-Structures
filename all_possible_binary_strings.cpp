class Solution {
private:
    void generateAllBinaryStrings(int n,string &s,vector<string>&vs){
        if(s.length() == n){
            vs.push_back(s);
            return;
        }
        string temp = s + "0";
        generateAllBinaryStrings(n,temp,vs);
        temp = s + "1";
        generateAllBinaryStrings(n,temp,vs);
    }
  public:
    vector<string> binstr(int n) {
        // code here
        string s = "";
        vector<string>vs;
        generateAllBinaryStrings(n,s,vs);
        return vs;
    }
};