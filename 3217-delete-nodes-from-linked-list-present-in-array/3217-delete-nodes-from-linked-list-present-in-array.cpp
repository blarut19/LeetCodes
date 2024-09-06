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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Sort nums.
        sort(nums.begin(), nums.end());

        // Handle case where head is in nums.
        while(in(head->val, nums))
            head = head->next;

        ListNode* prev = head;
        ListNode* curr = prev->next;
        // Delete any node whose value is in nums.
        while(curr != NULL){
            if(in(curr->val, nums)){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
    bool in(int num, vector<int>& nums){
        // Binary search to check if node value is in nums.
        return std::binary_search(nums.begin(), nums.end(), num);
    }
};