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
    class Compare {
    public:
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy = ListNode(0);

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (auto it : lists) {
            if (it)
                pq.push(it);
        }

        ListNode* res = &dummy;

        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();

            res->next = top;
            res = res->next;

            if (top->next) {
                pq.push(top->next);
            }
        }

        return dummy.next;
    }
};