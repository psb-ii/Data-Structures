class Solution {
private:
    Node* getMeetingPointInLinkedList(Node* head){
        Node* fast=head;
        Node* slow=head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == NULL || fast->next == NULL)
                break;
            if(slow == fast)
                return fast;
        }
        return NULL;
    }
    Node* getStartingOfALoop(Node* head,Node* meet){
        while(head != meet){
            head = head -> next;
            meet = meet -> next;
        }
        return meet;
    }
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* meet = getMeetingPointInLinkedList(head);
        int loop_length = 0;
        if(meet){
            Node* start = getStartingOfALoop(head,meet);
            loop_length = 1;
            Node* nex = start -> next;
            while(nex != start){
                nex = nex -> next;
                loop_length +=1;
            }
        }
        return loop_length;
    }
};