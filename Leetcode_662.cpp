class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode *,long long int>>qu;
        qu.push({root,0});
        while(qu.size()){
            int si = qu.size();
            int min_index = qu.front().second;
            int mini = 0;
            int maxi = 0;
            for(int i=0;i<si;i=i+1){
                if(i == 0)
                    mini = qu.front().second;
                if(i == si - 1)
                    maxi = qu.front().second;
                int new_ind = qu.front().second - min_index;
                if(qu.front().first -> left)
                    qu.push({qu.front().first->left,new_ind * 2ll + 1});
                if(qu.front().first -> right)
                    qu.push({qu.front().first ->right,new_ind * 2ll + 2});
                qu.pop();
            }
            res = max(res,maxi-mini+1);
        }
        return res;
    }
};