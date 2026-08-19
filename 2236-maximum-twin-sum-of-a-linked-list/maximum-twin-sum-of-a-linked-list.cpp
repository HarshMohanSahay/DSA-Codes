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
        // Step 1: find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: reverse second half
        ListNode* prev = NULL;
        while (slow) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Step 3: calculate max twin sum
        int maxSum = 0;
        ListNode* left = head;
        ListNode* right = prev;

        while (right) {
            maxSum = max(maxSum, left->val + right->val);
            left = left->next;
            right = right->next;
        }

        return maxSum;
    }
};

