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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> in, pre, post
        stack<pair<TreeNode *,int>>st;
        if(root)
            st.push({root,1});
        while(st.size()){
            TreeNode* t = st.top().first;
            int traversal = st.top().second;
            st.pop();
            if(traversal == 1){
                pre.push_back(t->val);
                st.push({t,traversal+1});
                if(t->left)
                    st.push({t->left,1});
            }
            else
            if(traversal == 2){
                in.push_back(t->val);
                st.push({t,traversal+1});
                if(t->right)
                    st.push({t->right,1});
            }
            else
                post.push_back(t->val);
        }
        return post;
    }
};