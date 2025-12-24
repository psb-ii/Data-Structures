class Solution {
public:
    int romanToInt(string s) {
        vector<int>values{1,5,10,50,100,500,1000};
        vector<char>roman{'I','V','X','L','C','D','M'};
        unordered_map<char,int>mapper;
        for(int i=0;i<values.size();i=i+1){
            mapper[roman[i]] = values[i];
        }
        int Number = 0;
        int prev = 0;
        for(int i=0;i<s.length();i=i+1){
            if(prev < mapper[s[i]])
                Number -=2*prev;
            Number +=mapper[s[i]];
            prev = mapper[s[i]];
        }
        return Number;
    }
};