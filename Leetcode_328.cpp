/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* odd_prev = odd;
        ListNode* f=even;
        while(odd || even){
            if(odd && odd -> next){
                odd->next=odd->next->next;
                odd=odd->next;
                if(odd)
                    odd_prev=odd;
            }
            else
                odd=NULL;
            if(even && even->next){
                even->next=even->next->next;
                even=even->next;
            }
            else
                even=NULL;
        }
        odd_prev -> next = f;
        return head;
    }
};