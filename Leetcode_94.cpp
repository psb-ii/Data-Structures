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
    void traveseInInOrderManner(TreeNode* r,vector<int>&traversal){
        if(r){
            traveseInInOrderManner(r->left,traversal);
            traversal.push_back(r->val);
            traveseInInOrderManner(r->right,traversal);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>traversal;
        traveseInInOrderManner(root,traversal);
        return traversal;
    }
};