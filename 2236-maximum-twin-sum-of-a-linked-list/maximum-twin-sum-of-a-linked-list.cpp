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
    int pairSum(ListNode* head) {
        vector<int> nodes;
        auto temp = head;
        while(temp){
            nodes.push_back(temp->val);
            temp = temp->next;
        }
        long long sum = 0;
        int i = 0;
        int j = nodes.size()-1;
        while(i<j){
            sum = max(sum, 1LL * nodes[i] + nodes[j]);
            i++;
            j--;
        }
        return sum;
    }
};