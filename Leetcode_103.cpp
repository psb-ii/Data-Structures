class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode *>q;
        if(root)
            q.push(root);
        bool rev = false;
        vector<int>v;
        while(q.size()){
            int s = q.size();
            for(int i=0;i<s;i=i+1){
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node -> val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(rev)
                reverse(v.begin(),v.end());
            rev = !rev;
            res.push_back(v);
            v.clear();
        }
        return res;  
    }
};