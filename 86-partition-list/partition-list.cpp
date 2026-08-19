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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smalllist = new ListNode(0);
        ListNode* largelist = new ListNode(0);
        ListNode* temp = head;
        ListNode* smallptr = smalllist;
        ListNode* largeptr = largelist;
        while(temp){
            if(temp->val<x){
                smallptr->next = new ListNode(temp->val);
                smallptr = smallptr->next;
            }
            else{
                largeptr->next = new ListNode(temp->val);
                largeptr = largeptr->next;
            }
            temp = temp->next;
        }
        smallptr->next = largelist->next;
        largeptr->next = NULL;
        return smalllist->next;
    }
};