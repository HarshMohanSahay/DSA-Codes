/**
 * Definition for singly-linked list.
 * struct Node {
 *     int val;
 *    Node *next;
 *    Node() : val(0), next(nullptr) {}
 *    Node(int x) : val(x), next(nullptr) {}
 *    Node(int x, Node *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // ListNode* prev = NULL;
        // ListNode* curr = head;
        // int n = 0;

        // if(!head || !head->next){
        //     return NULL;
        // }
        
        // while(curr!=NULL){
        //     curr = curr->next;
        //     n++;
        // }
        // int middle = n/2;
        // int count = 0;
        // curr = head;

        // while(curr!=NULL){
        //     prev = curr;
        //     curr = curr->next;
        //     count++;

        //     if(count==middle){
        //         prev->next = curr->next;
        //         return head;
        //     }

        // }
        // return head;
        if(head==NULL || head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        fast = fast->next->next;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next=slow->next->next;
        

        return head;
    }
};