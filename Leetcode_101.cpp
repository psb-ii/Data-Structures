class Solution {
private:
    bool isTheTreeSymmetricOrNot(TreeNode* l, TreeNode* r){
        if(l == NULL && r == NULL)
            return true;
        if((l == NULL && r != NULL) || (r == NULL && l != NULL))
            return false;
        cout<<l->val <<" "<<r->val<<endl;
        return (l->val == r->val) && isTheTreeSymmetricOrNot(l->left,r->right) && isTheTreeSymmetricOrNot(l->right,r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isTheTreeSymmetricOrNot(root->left,root->right);
    }
};