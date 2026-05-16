class Solution {
using v = vector<TreeNode *>;
private:
    TreeNode* getLowestCommonAncestor(v &path1,v &path2){
        TreeNode* lca;
        for(int i=path1.size()-1;i>=0;i=i-1){
            if(path1[i] == path2[i]){
                lca = path1[i];
                break;
            }
        }
        return lca;
    }
    void getPathForANode(TreeNode* root,TreeNode* target,v &path,vector<vector<TreeNode*>>&paths){
        path.push_back(root);
        if(root == target){
            paths.push_back(path);
            path.pop_back();
            return;
        }
        if(root -> left)
            getPathForANode(root->left,target,path,paths);
        if(root->right)
            getPathForANode(root->right,target,path,paths);
        path.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        v path1,path2;
        vector<vector<TreeNode *>>paths; 
        getPathForANode(root,p,path1,paths);
        getPathForANode(root,q,path2,paths);
        TreeNode* lca;
        if(paths[0].size() < paths[1].size())
            lca = getLowestCommonAncestor(paths[0],paths[1]);
        else
            lca = getLowestCommonAncestor(paths[1],paths[0]);
        return lca;
    }
};