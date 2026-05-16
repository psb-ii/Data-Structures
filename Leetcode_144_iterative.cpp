class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>traversal;
        stack<TreeNode* >st;
        if(root)
            st.push(root);
        while(st.size()){
            TreeNode* t = st.top();
            st.pop();
            traversal.push_back(t->val);
            if(t->right)
                st.push(t->right);
            if(t->left)
                st.push(t->left);
        }
        return traversal;
    }
};