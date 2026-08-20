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
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode* Nextnode = removeNodes(head->next);

        if(head->val<Nextnode->val){
            //delete head;
            return  Nextnode;
        }
        head->next = Nextnode;
        return head;
    }
};