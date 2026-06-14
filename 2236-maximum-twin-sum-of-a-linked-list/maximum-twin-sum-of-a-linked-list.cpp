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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    int pairSum(ListNode* head) {
        auto s = head;
        auto f = head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        auto endN = reverse(s);
        auto startN = head;
        long long sum = 0;

        while(endN){
            sum = max(sum, 1LL * startN->val + endN->val);
            endN = endN->next;
            startN = startN->next;
        }
        return sum;
    }
};


//Extra Space.
// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         vector<int> nodes;
//         auto temp = head;
//         while(temp){
//             nodes.push_back(temp->val);
//             temp = temp->next;
//         }
//         long long sum = 0;
//         int i = 0;
//         int j = nodes.size()-1;
//         while(i<j){
//             sum = max(sum, 1LL * nodes[i] + nodes[j]);
//             i++;
//             j--;
//         }
//         return sum;
//     }
// };