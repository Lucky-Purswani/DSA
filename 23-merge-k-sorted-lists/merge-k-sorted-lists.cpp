class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;

        if(a->val < b->val){
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        ListNode* res = lists[0];

        for(int i = 1; i < lists.size(); i++){
            res = merge(res, lists[i]);
        }

        return res;
    }
};