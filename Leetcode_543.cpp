class Solution {
private:
    int calculateHeight(TreeNode* node,int &diameter){
        if(!node)
            return 0;
        int lh = calculateHeight(node->left,diameter);
        int rh = calculateHeight(node->right,diameter);
        diameter = max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int height = calculateHeight(root,diameter);
        return diameter;
    }
};