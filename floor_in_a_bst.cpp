class Solution {
  public:
    int floor(Node* root, int x) {
        // code here
        int res = -1;
        while(root){
            if(root->data <= x){
                res = root->data;
                root = root->right;
            }
            else
                root = root->left;
        }
        return res;
    }
};