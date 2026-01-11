/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* getMeetingPointInACycle(ListNode* slow,ListNode* fast){
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return fast;
        }
        return NULL;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* meet=getMeetingPointInACycle(slow,fast);
        cout <<meet;
        if(meet){
            ListNode* start = head;
            while(start != meet){
                start = start->next;
                meet = meet->next;
            }
        }
        return meet;
    }
};