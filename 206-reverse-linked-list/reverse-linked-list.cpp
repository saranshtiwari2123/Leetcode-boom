class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* x = head;
        ListNode* y = x->next;
        ListNode* z = y->next;
        head->next = NULL;
        while(y){
            y->next = x;
            x = y;
            y = z;
            if(z) z = z->next;
        }
        return x;
    }
};