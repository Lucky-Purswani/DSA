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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto temp = head;
        int cnt=0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        if(cnt == n) return head->next;
        cnt = cnt - n - 1;
        temp = head;
        while(cnt > 0){
            temp = temp->next;
            cnt--;
        }
        if(temp->next)temp->next = temp->next->next;
        return head;
    }
};