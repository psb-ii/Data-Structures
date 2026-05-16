/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void updateParentToChildMap(unordered_map<TreeNode *,TreeNode *>&ma,TreeNode *root){
        TreeNode* curr = NULL;
        queue<TreeNode *>qu;
        qu.push(root);
        while(qu.size()){
            TreeNode *par = qu.front();
            qu.pop();
            if(par->left){
                qu.push(par->left);
                ma[par->left] = par;
            }
            if(par->right){
                qu.push(par->right);
                ma[par->right] = par;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *>ma;
        updateParentToChildMap(ma,root);
        vector<int>res;
        unordered_set<TreeNode *>se;
        queue<pair<TreeNode *,int>>qu;
        if(k == 0)
            res.push_back(target->val);
        if(ma.find(target) != ma.end()){
            se.insert(ma[target]);
            qu.push({ma[target],1});
        }
        se.insert(target);
        if(target->left){
            qu.push({target->left,1});
            se.insert(target->left);
        }
        if(target->right){
            qu.push({target->right,1});
            se.insert(target->right);
        }
        while(qu.size()){
            TreeNode* f= qu.front().first;
            int distance = qu.front().second;
            if(distance == k)   
                res.push_back(f->val);
            if(ma[f] && se.find(ma[f]) == se.end() && distance <k){
                se.insert(ma[f]);
                qu.push({ma[f],distance+1});
            }
            if(f->left && se.find(f->left) == se.end() && distance < k){
                se.insert(f->left);
                qu.push({f->left,distance+1});
            }
            if(f->right && se.find(f->right) == se.end() && distance < k){
                se.insert(f->right);
                qu.push({f->right,distance+1});
            }
            qu.pop();
        }
        return res;
    }
};