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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len = 0;
        auto temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }

        int rot = k % len;
        if(rot == 0) return head;
        int target = len - rot;
        auto ans = head;
        auto prev = head;
        while(ans && target){
            target--;
            prev = ans;
            ans = ans->next;
        }
        prev->next = NULL;
        temp = ans;
        while(temp && temp->next){
            temp = temp->next;
        }
        if(temp) temp->next = head;
        return ans;
    }
};