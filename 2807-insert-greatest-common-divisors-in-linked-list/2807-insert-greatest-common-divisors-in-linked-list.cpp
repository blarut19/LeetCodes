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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = prev->next;

        while(curr != NULL) {
            int val = gcd(prev->val, curr->val);
            ListNode* new_node = new ListNode();

            new_node->val = val;
            new_node->next = curr;
            prev->next = new_node;

            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};