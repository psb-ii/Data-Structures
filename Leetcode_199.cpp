class Solution {
private:
    void getRightSideViewOfBinaryTree(TreeNode* r,vector<int>&v,int level){
        if(r){
            if(v.size() == level)
                v.push_back(r->val);
            getRightSideViewOfBinaryTree(r->right,v,level+1);
            getRightSideViewOfBinaryTree(r->left,v,level+1);
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>right;
        int level = 0;
        getRightSideViewOfBinaryTree(root,right,level);
        return right;
    }
};