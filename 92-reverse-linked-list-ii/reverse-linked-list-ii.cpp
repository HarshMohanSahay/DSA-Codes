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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next){
            return head;
        }
        
        ListNode* curr = head;
        ListNode* dummynode = new ListNode(0);
        ListNode* prev = dummynode;
        dummynode->next = head;

        ListNode* temp = NULL;
        int l =left;
        while(--l){
         prev = curr;
         curr = curr->next;
        }

        for(int i =0;i<(right-left);i++){
            temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
        return dummynode->next;
    }
};