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
private:
    ListNode* reverse(ListNode* ptr){
        ListNode* dummy = NULL;
        ListNode* temp = ptr;
        while(temp){
            ListNode* nex = temp -> next;
            temp->next = dummy;
            dummy = temp;
            temp = nex;
        }
        return dummy;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next)
            return 1;
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* h=NULL;
        while(fast){
            if(fast->next == NULL || fast->next->next == NULL){
                h = reverse(slow->next);
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        while(h){
            // cout <<"Hi";
            // cout <<h->val <<" "<<temp->val;
            if(h->val == temp->val){
                h = h->next;
                temp = temp->next;
            }
            else
                return 0;
        }
        return 1;
        
    }
};