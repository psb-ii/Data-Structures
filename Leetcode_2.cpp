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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp = new ListNode(0);
        ListNode* h = temp;
        while(l1 || l2){
            // cout <<l1->val <<" "<<l2->val;
            int sum = carry;
            if(l2){
                sum += l2->val;
            }
            if(l1){
                sum += l1->val;
                l1->val = sum%10;
                temp->next=l1;
                temp=temp->next;
                l1=l1->next;
            }
            else{
                l2->val= sum%10;
                temp->next=l2;
                temp=temp->next;
            }
            if(l2)
                l2 = l2 -> next;
            carry = sum/10;
        }
        if(carry){
            ListNode* dummy = new ListNode(carry);
            temp->next = dummy;
        }
        return h->next;
    }
};