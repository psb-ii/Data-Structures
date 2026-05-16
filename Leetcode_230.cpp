class Solution {
private:
    void inorderTraversal(int k,vector<int>&traversal,TreeNode *root){
        if(root){
            inorderTraversal(k,traversal,root->left);
            traversal.push_back(root->val);
            inorderTraversal(k,traversal,root->right);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>res;
        inorderTraversal(k,res,root);
        return res[k-1];
    }
};toic