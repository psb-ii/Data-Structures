class Solution {
private:
    int checkIfBalanced(TreeNode* root, bool& balanced){
        if(root == NULL)
            return 0;
        int lh = checkIfBalanced(root->left,balanced);
        int rh = checkIfBalanced(root->right,balanced);
        if(balanced && abs(lh-rh) > 1)
            balanced = 0; 
        return 1 + max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = 1;
        int h = checkIfBalanced(root,balanced);
        return balanced;
    }
};