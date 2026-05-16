class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(root == NULL)
            return node;
        TreeNode* temp = root;
        TreeNode* prev = NULL;
        while(temp){
            prev = temp;
            if(temp->val > val)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if(prev->val > val)
            prev->left = node;
        else
            prev->right = node;
        return root;
    }
};