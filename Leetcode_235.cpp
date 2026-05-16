class Solution {
private:
    TreeNode* lcaOfBST(TreeNode* root,TreeNode *p,TreeNode*q){
        if(root->val <= q->val && root->val >= p->val)
            return root;
        if(root->val < p->val)
            return lcaOfBST(root->right,p,q);
        return lcaOfBST(root->left,p,q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val <= q->val)
            return lcaOfBST(root,p,q);
        return lcaOfBST(root,q,p);
    }
};