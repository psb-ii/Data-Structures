class Solution {
private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    void inorderTraversal(TreeNode* node){
        if(node){
            inorderTraversal(node->left);
            if(prev && prev->val > node->val){
                if(first == NULL){
                    first=prev;
                    middle=node;
                }
                else
                    last=node;
            }
            prev=node;
            inorderTraversal(node->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        first = NULL;
        middle = NULL;
        last = NULL;
        prev = NULL;
        inorderTraversal(root);
        if(first && last)
            swap(first->val,last->val);
        else
            swap(first->val,middle->val);
    }
};