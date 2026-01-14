/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* temp = head;
        Node* z_Node = new Node(-1);
        Node* o_Node = new Node(-1);
        Node* t_Node = new Node(-1);
        Node* z_temp = z_Node;
        Node* o_temp = o_Node;
        Node* t_temp = t_Node;
        while(temp){
            if(temp->data == 0){
                z_temp->next = temp;
                z_temp = temp;
            }
            else
            if(temp->data == 1){
                o_temp->next = temp;
                o_temp = temp;
            }
            else{
                t_temp->next = temp;
                t_temp = temp;
            }
            temp = temp -> next;
        }
        t_temp->next = NULL;
        if(o_temp -> data == 1){
            z_temp->next = o_Node->next;
            o_temp->next = t_Node->next;
        }
        else
            z_temp->next = t_Node->next;
        return z_Node->next;
        
    }
};