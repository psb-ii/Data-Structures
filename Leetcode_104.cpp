class Solution {
private:
    int calculateDepthOfATree(TreeNode* node){
        if(node == NULL)
            return 0;
        return 1 + max(calculateDepthOfATree(node->left),calculateDepthOfATree(node->right));
    }
public:
    int maxDepth(TreeNode* root) {
        return calculateDepthOfATree(root);
    }
};