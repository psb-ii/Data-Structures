class Solution {
private:
    Node* reverseList(Node* head){
        Node* dummy = NULL;
        Node* temp = head;
        while(temp){
            Node* nex = temp->next;
            temp->next = dummy;
            dummy = temp;
            temp = nex;
        }
        return dummy;
    }
  public:
    Node* addOne(Node* head) {
        // Your Code here
        Node* reversedhead = reverseList(head);
        Node* temp = reversedhead;
        int carry=1;
        Node* prev = NULL;
        while(temp){
            int v = temp->data + carry;
            temp->data = v%10;
            carry = v/10;
            prev = temp;
            temp = temp->next;
        }
        if(carry){
            Node* n = new Node(carry);
            prev->next=n;
            prev=prev->next;
        }
        reversedhead = reverseList(reversedhead);
        return reversedhead;
    }
};