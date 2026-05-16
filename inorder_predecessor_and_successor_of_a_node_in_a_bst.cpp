/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* node = root;
        Node *pre=NULL;
        Node *succ=NULL;
        while(node){
            if(node->data < key){
                pre=node;
                node = node->right;
            }
            else
                node = node->left;
        }
        node=root;
        while(node){
            if(node->data > key){
                succ=node;
                node = node->left;
            }
            else
                node = node->right;
        }
        vector<Node*>v{pre,succ};
        return v;
    }
};