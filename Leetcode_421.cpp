class Solution {
    class TrieNode {
        public:
            TrieNode* links[2];
        
            void put(int num,TrieNode* node){
                links[num] = node;
            }

            bool containsKey(int num){
                return (links[num] != NULL);
            }

            TrieNode* get(int num){
                return links[num];
            }
    };
    TrieNode *root;
public:

    Solution() {
        root = new TrieNode();
    }

    int findMaximumXOR(vector<int>& nums) {
        for(int i=0;i<nums.size();i=i+1){
            TrieNode* node = root;
            for(int j=31;j>=0;j=j-1){
                int num = 0;
                if((1 << j) & nums[i])
                    num = 1;
                if(!(node -> containsKey(num)))
                    node -> put(num,new TrieNode());
                node = node -> get(num);
            }
        }

        int res = 0;
        int curr_res = 0;
        for(int i=0;i<nums.size();i=i+1){
            TrieNode* node = root;
            curr_res = 0;
            for(int j=31;j>=0;j=j-1){
                int num = (1 << j) & nums[i] ? 1 : 0;
                int counter_num = 1 - num;
                if(node -> containsKey(counter_num)){
                    curr_res = curr_res | (1 << j);
                    node = node -> get(counter_num);
                }
                else{
                    node = node -> get(num);
                }
            }
            res = max(res,curr_res);
        }
        return res;
    }
};