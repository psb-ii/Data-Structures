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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode *,int>>q;
        vector<vector<int>>res;
        vector<int>temp;
        if(root)
            q.push({root,0});
        int prev = 0;
        while(q.size()){
            TreeNode* r = q.front().first;
            int level = q.front().second;
            q.pop();
            if(r->left)
                q.push({r->left,level+1});
            if(r->right)
                q.push({r->right,level+1});
            if(level != prev){
                res.push_back(temp);
                temp.clear();
                prev = level;
            }
            temp.push_back(r->val);
        }
        if(temp.size())
            res.push_back(temp);
        return res;
    }
};