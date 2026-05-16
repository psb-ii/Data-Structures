class Solution {
private:
    TreeNode* getRightMostNode(TreeNode* node){
        while(node->right){
            node = node -> right;
        }
        return node;
    }
    TreeNode* helper(TreeNode* node){
        if(node->left == NULL)
            return node->right;
        if(node->right == NULL)
            return node->left;
        TreeNode* right_most = getRightMostNode(node->left);
        TreeNode* immediate_right = node->right;    
        right_most->right = immediate_right;
        return node->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        if(root->val == key)
            return helper(root);
        TreeNode* dummy = root;
        while(dummy){
            if(dummy->val <= key){
                if(dummy->right && dummy->right->val == key){
                    dummy->right = helper(dummy->right);
                    break;
                }
                else
                    dummy = dummy->right;
            }
            else{
                if(dummy->left && dummy->left->val == key){
                    dummy->left = helper(dummy->left);
                    break;
                }
                else
                    dummy = dummy -> left;
            }
        }
        return root;
    }
};