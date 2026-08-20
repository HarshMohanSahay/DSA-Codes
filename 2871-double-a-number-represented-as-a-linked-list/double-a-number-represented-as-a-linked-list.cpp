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
    ListNode* doubleIt(ListNode* head) {
        if(head->val>=5){
            ListNode* newnode = new ListNode(0);
            newnode->next= head;
            head = newnode;
        }

        ListNode* curr = head;
        while(curr ){
            if(curr->next!=NULL && curr->next->val>=5){
                curr->val = (curr->val*2+1)%10;
            }
            else{
                curr->val = (curr->val*2)%10;
            }
            curr = curr->next;
        }
        return head;
    }
};