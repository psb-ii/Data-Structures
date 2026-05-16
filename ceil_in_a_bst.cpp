class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int res = -1;
        while(root){
            if(root->data >= x){
                res = root->data;
                root = root->left;
            }
            else
                root = root->right;
        }
        return res;
    }
};