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
    int calculateLength(ListNode* head){
        int n=0;
        while(head){
            n++;
            head=head->next;
        }
        return n;
    }
    ListNode* giveNewStartingPoint(ListNode *h,int l){
        while(l--)
            h=h->next;
        return h;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = calculateLength(headA);
        int l2 = calculateLength(headB);
        ListNode* newHeadA = NULL;
        if(l1 < l2){
            newHeadA=headA;
            headA=headB;
            headB=newHeadA;
        }
        ListNode* newHeadB=headB;
        newHeadA = giveNewStartingPoint(headA,abs(l1-l2));
        while(newHeadA != newHeadB){
            newHeadA = newHeadA -> next;
            newHeadB = newHeadB -> next;
        }
        return newHeadA;
    }
};