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
    ListNode* reversell(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* nextnode = NULL;
        ListNode* curr = head;
        while(curr){
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reversell(l1);
        l2 = reversell(l2);

        int sum =0;
        int carry =0;
        ListNode* ans = new ListNode(0);
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            sum = sum%10;
            ans->val = sum ;
            ListNode* carrynode = new ListNode(carry);
            carrynode->next = ans;
            ans = carrynode;
            sum = carry ;


        }
        if(carry ==0){
            return ans->next;
        }
        return ans;
    }
};