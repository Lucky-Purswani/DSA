class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int len = 1;
        ListNode* last = head;

        // find length + last node
        while(last->next){
            last = last->next;
            len++;
        }

        int rot = k % len;
        if(rot == 0) return head;

        // make circular

        int target = len - rot;

        ListNode* ans = head;
        ListNode* temp = NULL;

        while(target--){
            temp = ans;
            ans = ans->next;
        }

        // break circle
        temp->next = NULL;
        last->next = head;

        return ans;
    }
};