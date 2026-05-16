class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start = NULL;
        ListNode* end = head;
        ListNode* temp = head;
        int count = k;
        while(temp){
            if(count){
                if(!start)
                    start = head;
                else
                    start = start->next;
                count--;
            }
            else{
                    end = end -> next;
            }
            temp = temp -> next;
        }
        swap(start->val,end->val);
        return head;
    }
};