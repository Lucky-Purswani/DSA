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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* temp = new ListNode(-1);
        auto ans = temp;
        auto t1 = list1;
        auto t2 = list2;
        while(t1 && t2){
            if(t1->val <= t2->val){
                temp->next = t1;
                t1 = t1->next;
                temp = temp->next;
            }
            else{
                temp->next = t2;
                t2 = t2->next;
                temp = temp->next;
            }
        }
        if(t1) temp->next = t1;
        if(t2) temp->next = t2;
        return ans->next;
    }
};