class Solution {
private:
    bool checkForBSTNature(TreeNode *root,long long int mini,long long int maxi){
        if(root == NULL)
            return true;
        if(root->val > mini && root->val < maxi)
            return checkForBSTNature(root->left,mini,root->val) && checkForBSTNature(root->right,root->val,maxi);
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return checkForBSTNature(root,-1e12,1e12);
    }
};