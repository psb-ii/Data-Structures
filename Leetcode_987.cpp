class Solution {
using m = map<int,map<int,multiset<int>>>;
private:
    void updateVerticalTraversalMap(TreeNode* root,m &ma,int ordinate,int abscissa){
        if(root){
            ma[ordinate][abscissa].insert(root->val);
            updateVerticalTraversalMap(root->left,ma,ordinate-1,abscissa+1);
            updateVerticalTraversalMap(root->right,ma,ordinate+1,abscissa+1);
        }
        return;
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        m ma;
        int ordinate = 0;
        int abscissa = 0;
        updateVerticalTraversalMap(root,ma,ordinate,abscissa);
        for(auto outer=ma.begin();outer!=ma.end();outer++){
            vector<int>v;
            for(auto it=outer->second.begin();it!=outer->second.end();it++){
                for(auto s=it->second.begin();s!=it->second.end();s++)
                    v.push_back(*s);
            }
            res.push_back(v);
        }
        return res;
    }
};