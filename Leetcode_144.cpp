/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void traveseInPreOrderManner(TreeNode* r,vector<int>&traversal){
        if(r){
            traversal.push_back(r->val);
            traveseInPreOrderManner(r->left,traversal);
            traveseInPreOrderManner(r->right,traversal);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>traversal;
        traveseInPreOrderManner(root,traversal);
        return traversal;
    }
};