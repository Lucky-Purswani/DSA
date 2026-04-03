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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex = NULL;
        int pos = 1;
        while(curr){
            if(pos == left && curr){
                //swapping
                ListNode* ls = prev; //fine
                ListNode* rs = NULL; 
                ListNode* listLeftNode = curr;
                ListNode* listRightNode = NULL;
                prev = NULL;
                while(pos <= right && curr){
                    nex = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nex;
                    rs = curr;
                    listRightNode = prev;
                    pos++;
                }
                if(ls)ls->next = listRightNode;
                else head = listRightNode;
                listLeftNode->next = rs;
                break;
            }
            else{
                nex = curr->next;
                prev = curr;
                curr = nex;
                pos++;
            }
        }
        return head;
    }
};