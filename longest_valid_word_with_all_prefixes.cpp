class Solution {
    class TrieNode{
        public:
            TrieNode* links[26];
            bool flag = false;
        
            bool containsKey(char ch){
                return (links[ch - 'a'] != NULL);
            }
            
            void put(char ch,TrieNode* node){
                links[ch - 'a'] = node;
            }
            
            TrieNode* get(char ch){
                return links[ch - 'a'];
            }
            
            void setEnd(){
                flag = true;
            }
            
            bool isEnd(){
                return flag;
            }
    };
    TrieNode *root;
  public:
    
    Solution() {
        root = new TrieNode();
    }
    
    string longestValidWord(vector<string>& words) {
        // code here
        
        for(int i=0;i<words.size();i=i+1){
            TrieNode *node = root;
            for(int j=0;j<words[i].length();j=j+1){
                if(!(node -> containsKey(words[i][j]))){
                    node -> put(words[i][j], new TrieNode());
                }
                node = node -> get(words[i][j]);
            }
            node -> setEnd();
        }
        
        string s = "";
        int maxLen = 0;
        
        for(int i=0;i<words.size();i=i+1){
            TrieNode *node = root;
            for(int j=0;j<words[i].length();j=j+1){
                if(node -> containsKey(words[i][j])){
                    node = node -> get(words[i][j]);
                    if(node -> isEnd()){
                        if(j == words[i].length() - 1){
                            if(words[i].length() == maxLen)
                                s = s < words[i] ? s : words[i];
                            else
                            if(words[i].length() > maxLen){
                                s = words[i];
                                maxLen = words[i].length();
                            }
                        }
                    }
                    else
                        break;
                }
                else
                    break;
            }
        }
        
        return s;
    }
};
