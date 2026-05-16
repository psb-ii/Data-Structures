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
    int calculateHeightOfLeftTree(TreeNode* root){
        int height = 0;
        while(root){
            height +=1;
            root = root->left;
        }
        return height;
    }
    int calculateHeightOfRightTree(TreeNode* root){
        int height = 0;
        while(root){
            height +=1;
            root = root->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int lh = calculateHeightOfLeftTree(root);
        int rh = calculateHeightOfRightTree(root);
        if(lh == rh)
            return pow(2,lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};