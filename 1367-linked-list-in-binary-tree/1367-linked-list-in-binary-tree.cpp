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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        // Use BFS to find a node that can start the seqence.
        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* n = q.front();
            // If a node has the same value as the sequence check it's children.
            if(n->val == head->val)
                if(try_node(head, n))
                    return true;
            q.pop();

            if(n->left != NULL)
                q.push(n->left);
            if(n->right != NULL)
                q.push(n->right);
        }

        return false;
    }
    bool try_node(ListNode* head, TreeNode* root){
        // If we reach the end of the sequence then it's a match.
        if(head == NULL)
            return true;
        // If we are at a leaf before the end of sequence then it's not a match.
        if(root == NULL)
            return false;
        // Check whether the node value matches current value in sequence.
        if(head->val == root->val){
            // Recursively call the function on it's children.
            return try_node(head->next, root->left) || try_node(head->next, root->right);
        }
        return false;
    }
};