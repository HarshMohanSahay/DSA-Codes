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
        if(!head || !head->next) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextptr = NULL;
        while(curr){
            nextptr = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nextptr; 

        }
        return prev;

    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev = reversell(slow);
        ListNode* curr = head;

        while(rev->next){
            ListNode* tempcurr = curr->next;
            curr ->next = rev;
            ListNode* temprev = rev->next;
            rev->next = tempcurr;
            curr = tempcurr;
            rev = temprev;
        }
    }
};