class Solution {
private:
    TreeNode* treeBuilder(vector<int>&preorder,int pre_start,int pre_end,vector<int>&inorder,int in_start,int in_end,unordered_map<int,int>&ma){
        if(pre_start > pre_end)
            return NULL;
        TreeNode *node = new TreeNode(preorder[pre_start]);
        int pos = ma[preorder[pre_start]];
        int node_nums = pos - in_start;
        node->left = treeBuilder(preorder,pre_start+1,pre_start+node_nums,inorder,in_start,in_start+node_nums,ma);
        node->right = treeBuilder(preorder,pre_start+node_nums+1,pre_end,inorder,in_start+node_nums+1,in_end,ma);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>ma;
        for(int i=0;i<inorder.size();i=i+1){
            ma[inorder[i]]=i;
        }
        TreeNode *node = treeBuilder(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,ma);
        return node;
    }
};