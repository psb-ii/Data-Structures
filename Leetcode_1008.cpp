lass Solution {
private:
    TreeNode* buildBstFromPreorderTraversal(vector<int>&preorder,int &ind,int bound){
        cout <<ind <<" ";
        if(ind>=preorder.size() || preorder[ind] > bound)
            return NULL;
        TreeNode* node = new TreeNode(preorder[ind]);
        ind +=1;
        node->left = buildBstFromPreorderTraversal(preorder,ind,node->val);
        node->right = buildBstFromPreorderTraversal(preorder,ind,bound);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return buildBstFromPreorderTraversal(preorder,i,INT_MAX);
    }
};