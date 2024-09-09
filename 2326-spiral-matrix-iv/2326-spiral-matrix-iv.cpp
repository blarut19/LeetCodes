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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Create spiral vector.
        vector<vector<int>> spiral(m);
        vector<int> row(n);
        std::fill(row.begin(), row.end(), -1);
        std::fill(spiral.begin(), spiral.end(), row);

        // Define position, rotation matrix and domains
        int pos[] = {0, m-1};
        int dir[] = {1, 0};
        int horizontal_domain[] = {-1, n};
        int vertical_domain[] = {0, m};

        while(head != NULL){
            spiral[m-1-pos[1]][pos[0]] = head->val;
            head = head->next;

            // Step forward.
            pos[0] += dir[0];
            pos[1] += dir[1];

            bool turn = false;

            if(pos[0] < horizontal_domain[0]) {
                turn = true;
                // Update domain.
                horizontal_domain[1] --;
            }
            else if(pos[0] >= horizontal_domain[1]) {
                turn = true;
                // Update domain.
                horizontal_domain[0] ++;
            }
            else if(pos[1] < vertical_domain[0]) {
                turn = true;
                // Update domain.
                vertical_domain[1] --;
            }
            else if(pos[1] >= vertical_domain[1]) {
                turn = true;
                // Update domain.
                vertical_domain[0] ++;
            }
            if(turn) {
                // Step back.
                pos[0] -= dir[0];
                pos[1] -= dir[1];
                // Turn right.
                int temp = dir[0];
                dir[0] = dir[1];
                dir[1] = -temp;
                // Step forward.
                pos[0] += dir[0];
                pos[1] += dir[1];}
            }

        return spiral;
    }
};