class Solution {
    class TrieNode {
        public:
            TrieNode* links[26];
            bool flag = false;
            
            void put(char ch,TrieNode* node){
                links[ch - 97] = node;
            }
            
            TrieNode* get(char ch){
                return links[ch - 97];
            }
            
            bool containsKey(char ch){
                return (links[ch - 97] != NULL);
            }
            
            void setEnd(){
                flag = true;
            }
            
            bool isEnd(){
                return flag;
            }
    };
    
    TrieNode* root;
  public:
    
    Solution() {
        root = new TrieNode();
    }
    
    int countSubs(string& s) {
        // code here
        int count = 0;
        for(int i=0;i<s.length();i=i+1){
            TrieNode * node = root;
            for(int j=i;j<s.length();j=j+1){
                if(!(node -> containsKey(s[j])))
                    node->put(s[j],new TrieNode());
                node = node -> get(s[j]);
                if(! (node -> isEnd()) ){
                    node -> setEnd();
                    count +=1;
                }
            }
        }
        return count;
    }
};