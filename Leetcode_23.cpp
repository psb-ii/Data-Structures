class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>minh;
        for(int i=0;i<lists.size();i=i+1){
            if(lists[i])
                minh.push({lists[i]->val,lists[i]});
        }
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while(minh.size()){
            ListNode* node = minh.top().second;
            minh.pop();
            curr->next = node;
            curr = curr->next;
            if(node->next){
                minh.push({node->next->val,node->next});
            }
        }
        return dummy->next;
    }
};