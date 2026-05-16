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
    void traverseInPostManner(TreeNode* r,vector<int>& traversal){
        if(r){
            traverseInPostManner(r->left,traversal);
            traverseInPostManner(r->right,traversal);
            traversal.push_back(r->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>traversal;
        traverseInPostManner(root,traversal);
        return traversal;
    }
};