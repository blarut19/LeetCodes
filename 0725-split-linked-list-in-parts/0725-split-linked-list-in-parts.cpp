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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = len(head);
        int m = n / k;
        int r = n % k;
        
        vector<ListNode *> ans;
        ListNode* prev = head;
        ListNode* curr;
        
        for(int i = 0; i < k; i++){
            for(int j = 0; j < m; j++){
                if(curr){
                    prev = curr;
                    curr = curr->next;
                }
            }
            if(r-- > 0){
                prev = curr;
                curr = curr->next;
            }
            
            if(prev)
                prev->next = NULL;
                
            ans.push_back(head);
            head = prev = curr;
        } 

        return ans;
    }
    int len(ListNode* head){
        if(head == NULL)
            return 0;
        return 1+len(head->next);
    }
};