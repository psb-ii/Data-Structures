class Solution {
private:
    int getMaxStartIndex(int ind,string &s1,string &s2){
        int i = s2.length() - 1;
        while(i>=0){
            if(s2[i] == s1[ind])
                i--;
            if(i<0)
                break;
            ind--;
        }
        return ind;
    }
  public:
    string minWindow(string& s1, string& s2) {
        int i = 0;
        int j = 0;
        int curr = 0;
        string res ="";
        int start_ind = 0;
        int min_window = INT_MAX;
        while(j<s1.length()){
            if(s1[j] == s2[i])
                i++;
            if(i == s2.length()){
                int s_ind = getMaxStartIndex(j,s1,s2);
                if(min_window > j - s_ind + 1){
                    min_window = j - s_ind + 1;
                    start_ind = s_ind;
                }
                j=s_ind;
                i=0;
            }
            j++;
        }
        if(min_window == INT_MAX)
            return "";
        return s1.substr(start_ind,min_window);
    }
};
