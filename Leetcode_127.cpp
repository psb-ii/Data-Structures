class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>se;
        for(int i=0;i<wordList.size();i=i+1){
            se.insert(wordList[i]);
        }
        if(se.find(beginWord) != se.end())
            se.erase(beginWord);
        queue<pair<string,int>>qu;
        qu.push({beginWord,1});
        while(qu.size()){
            string word = qu.front().first;
            int step = qu.front().second;
            qu.pop();
            if(word == endWord)
                return step;
            for(int i=0;i<word.length();i=i+1){
                char org = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(se.find(word) != se.end()){
                        se.erase(word);
                        qu.push({word,step+1});
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
};